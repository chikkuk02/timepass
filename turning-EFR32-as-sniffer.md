# EFR32 Sniffer Tool – Configuration Guide

## Overview

The **EFR32 Sniffer Tool** is designed to help developers and engineers monitor and analyze wireless communication traffic using EFR32-based boards. It transforms your development board into a sniffer device, allowing for real-time traffic inspection across supported wireless protocols such as **IEEE 802.15.4**, **Bluetooth Low Energy**, and **IEEE 802.15.4 Sub-GHz**.

This tool is particularly useful in:

- **Debugging communication issues** within wireless applications.
- **Validating packet structures** and protocol compliance.
- **Monitoring wireless environments** during development and testing phases.
- **Gaining visibility into over-the-air data**, which is essential for troubleshooting and optimization.

> ℹ️ This guide focuses on configuring the sniffer using the **Sniffer Configurator Tool**, which is the recommended and user-friendly method supported by the Simplicity Studio environment.

---

## Prerequisites

Before you begin, ensure you have the following:

- An **EFR32 development board**.
- The latest version of **Simplicity Studio** installed.
- The **Sniffer Configurator Tool** available via the Debug Adapter window.
- A valid **debug adapter** connected to your EFR32 board via USB.

---

## Step-by-Step Configuration Using the Sniffer Configurator Tool

### 1. Open the Sniffer Configurator

Navigate to the **Debug Adapters** view within Simplicity Studio.  
Right-click on the desired debug adapter and select **Sniffer Configurator**


![Step 1](images/sniffer_step1.png)

---

### 2. Select the Target Debug Adapter

In the dialog that appears, choose the debug adapter that you want to turn into a sniffer. Click *Next*

![Step 2](images/sniffer_step2.png)

---

### 3. Upload Sniffer Firmware (First-Time Only)

If this is your first time turning the board into a sniffer:

- Check the box for the appropriate debug adapter.
- Click *Select and upload sniffer to checked devices*
- Then click *Next*


![Step 3](images/sniffer_step3.png)

---

### 4. Configure Sniffer Parameters

In the parameter configuration window:

- Choose your desired protocol from the dropdown menu:
  - `IEEE 802.15.4`
  - `Bluetooth Low Energy`
  - `IEEE 802.15.4 Sub-GHz`
- Adjust frequency, channel, and data rate settings as required for your environment.

After configuration, click **Apply EFR32 sniffer Configuration** and *Finish*.


![Step 4](images/sniffer_step4.png)

---

## Verifying and Starting the Capture

### 5. Start Packet Capture

Return to the **Debug Adapters** panel.

- Select the same device you configured as a sniffer.
- Click **Start Capture**

![Step 5](images/sniffer_step5.png)

---

## Viewing Network Traffic

Upon starting capture, the **Network Analyzer** will launch automatically and begin capturing wireless traffic in real time.  
You should now see incoming frames and packets visualized, indicating successful sniffer operation.

![Capture Output](images/sniffer_output.png)

---

## Conclusion

With the EFR32 board now functioning as a sniffer, you can efficiently monitor wireless activity in your system, gaining detailed insights critical for debugging and validation. This tool supports multiple protocols and offers a reliable, repeatable method for wireless traffic analysis in a professional development workflow.

For any additional configuration needs or troubleshooting, please refer to the full [Simplicity Studio Documentation](https://www.silabs.com/developers/simplicity-studio).









