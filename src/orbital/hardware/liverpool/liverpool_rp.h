/**
 * Liverpool Root Port (RP) PCI device.
 *
 * Copyright 2017-2021. Orbital project.
 * Released under MIT license. Read LICENSE for more details.
 *
 * Authors:
 * - Alexandro Sanchez Bach <alexandro@phi.nz>
 */

#pragma once

#include <orbital/core.h>

enum {
    LIVERPOOL_RP_DEV = 0x2,
    LIVERPOOL_RP_FNC = 0x0,
};

constexpr auto LIVERPOOL_RP_DID = static_cast<PCIDeviceId>(0x1438);

struct LiverpoolRPDeviceConfig : PCIeDeviceConfig {
    LiverpoolRPDeviceConfig(PCI_DF df = PCI_DF(LIVERPOOL_RP_DEV, LIVERPOOL_RP_FNC))
        : PCIeDeviceConfig(df, PCI_VENDOR_ID_AMD, LIVERPOOL_RP_DID, 0x1, PCI_CLASS_BRIDGE_HOST) {
    }
};

class LiverpoolRPDevice final : public PCIeDevice {
public:
    LiverpoolRPDevice(PCIeBus* bus, const LiverpoolRPDeviceConfig& config = {});
    ~LiverpoolRPDevice();

    // Device interface
    void reset() override;
};
