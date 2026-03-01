#include "app/framework/include/af.h"
#include "stack/include/network-formation.h"

static sl_zigbee_event_t form_network_event;
static void form_network_event_handler(sl_zigbee_event_t *event);
static void permit_join(void);

void emberAfRadioNeedsCalibratingCallback(void)
{
    sl_mac_calibrate_current_channel();
}

void emberAfMainInitCallback(void)
{
    emberAfCorePrintln("Coordinator Init");
    sl_zigbee_event_init(&form_network_event, form_network_event_handler);
    sl_zigbee_event_set_active(&form_network_event);
}

void emberAfTrustCenterJoinCallback(EmberNodeId newNodeId,
                                    EmberEUI64 newNodeEui64,
                                    EmberNodeId parentOfNewNode,
                                    EmberDeviceUpdate status,
                                    EmberJoinDecision decision)
{
    emberAfCorePrintln("TC Join: node 0x%04X status 0x%02X decision 0x%02X",
                       newNodeId, status, decision);
}

static void form_network_event_handler(sl_zigbee_event_t *event)
{
    sl_zigbee_event_set_inactive(event);

    EmberNetworkStatus state = emberNetworkState();
    emberAfCorePrintln("Network state: 0x%02X", state);

    if (state == EMBER_JOINED_NETWORK) {
        emberAfCorePrintln("Already on network, leaving...");
        emberLeaveNetwork();
        return;
    }

    if (state == EMBER_NO_NETWORK) {
        EmberInitialSecurityState securityState;
        memset(&securityState, 0, sizeof(EmberInitialSecurityState));
        securityState.bitmask = EMBER_NO_SECURITY;
        emberSetInitialSecurityState(&securityState);

        EmberNetworkParameters parameters;
        parameters.panId        = 0x1234;
        parameters.radioChannel = 12;
        parameters.radioTxPower = 0;

        EmberStatus status = emberFormNetwork(&parameters);
        emberAfCorePrintln("emberFormNetwork: 0x%02X", status);
    }
}

static void permit_join(void)
{
    EmberStatus status = emberPermitJoining(0xFF);
    emberAfCorePrintln("emberPermitJoining: 0x%02X", status);
}

void emberAfStackStatusCallback(EmberStatus status)
{
    if (status == EMBER_NETWORK_UP) {
        emberAfCorePrintln("Network UP");
        permit_join();
    } else if (status == EMBER_NETWORK_DOWN) {
        emberAfCorePrintln("Network DOWN - reforming...");
        sl_zigbee_event_set_active(&form_network_event);
    }
}
