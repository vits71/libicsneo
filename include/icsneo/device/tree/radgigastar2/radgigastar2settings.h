#ifndef __RADGIGASTAR2SETTINGS_H_
#define __RADGIGASTAR2SETTINGS_H_

#include <stdint.h>
#include "icsneo/device/idevicesettings.h"

#ifdef __cplusplus

namespace icsneo
{

#endif

#pragma pack(push, 2)
	typedef struct
	{
		uint32_t ecu_id;
		uint16_t perf_en;
		struct
		{
			uint16_t hwComLatencyTestEn : 1;
			uint16_t disableUsbCheckOnBoot : 1;
			uint16_t reserved : 14;
		} flags;
		uint16_t network_enabled_on_boot;
		CAN_SETTINGS can1;
		CANFD_SETTINGS canfd1;
		CAN_SETTINGS can2;
		CANFD_SETTINGS canfd2;
		CAN_SETTINGS can3;
		CANFD_SETTINGS canfd3;
		CAN_SETTINGS can4;
		CANFD_SETTINGS canfd4;

		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_1;
		uint16_t iso_parity_1;
		uint16_t iso_msg_termination_1;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_2;
		uint16_t iso_parity_2;
		uint16_t iso_msg_termination_2;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_3;
		uint16_t iso_parity_3;
		uint16_t iso_msg_termination_3;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_4;
		uint16_t iso_parity_4;
		uint16_t iso_msg_termination_4;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_5;
		uint16_t iso_parity_5;
		uint16_t iso_msg_termination_5;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_6;
		uint16_t iso_parity_6;
		uint16_t iso_msg_termination_6;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_7;
		uint16_t iso_parity_7;
		uint16_t iso_msg_termination_7;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_8;
		uint16_t iso_parity_8;
		uint16_t iso_msg_termination_8;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_9;
		uint16_t iso_parity_9;
		uint16_t iso_msg_termination_9;
		ISO9141_KEYWORD2000_SETTINGS iso9141_kwp_settings_10;
		uint16_t iso_parity_10;
		uint16_t iso_msg_termination_10;
		uint64_t network_enables;
		uint64_t network_enables_2;
		uint64_t termination_enables;
		TIMESYNC_ICSHARDWARE_SETTINGS timeSyncSettings;
		RAD_REPORTING_SETTINGS reporting;
		int16_t iso15765_separation_time_offset;
		uint32_t pwr_man_timeout;
		uint16_t pwr_man_enable;
		RAD_GPTP_SETTINGS gPTP;
		STextAPISettings text_api;
		DISK_SETTINGS disk;
		LOGGER_SETTINGS logger;
		LIN_SETTINGS lin1;
		LIN_SETTINGS lin2;
		LIN_SETTINGS lin3;
		LIN_SETTINGS lin4;
		LIN_SETTINGS lin5;
		LIN_SETTINGS lin6;
		LIN_SETTINGS lin7;
		LIN_SETTINGS lin8;
		LIN_SETTINGS lin9;
		LIN_SETTINGS lin10;
		// TODO more LIN
		// Ethernet SFP
		ETHERNET_SETTINGS2 ethernet1;
		ETHERNET_SETTINGS2 ethernet2;
		// Ethernet General
		OP_ETH_GENERAL_SETTINGS opEthGen;
		// 100/1000T1
		ETHERNET_SETTINGS2 ethT1;
		OP_ETH_SETTINGS opEth1;
		ETHERNET_SETTINGS2 ethT12;
		OP_ETH_SETTINGS opEth2;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s1;
		ETHERNET10T1S_SETTINGS t1s1;
		ETHERNET10T1S_SETTINGS_EXT t1s1Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s2;
		ETHERNET10T1S_SETTINGS t1s2;
		ETHERNET10T1S_SETTINGS_EXT t1s2Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s3;
		ETHERNET10T1S_SETTINGS t1s3;
		ETHERNET10T1S_SETTINGS_EXT t1s3Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s4;
		ETHERNET10T1S_SETTINGS t1s4;
		ETHERNET10T1S_SETTINGS_EXT t1s4Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s5;
		ETHERNET10T1S_SETTINGS t1s5;
		ETHERNET10T1S_SETTINGS_EXT t1s5Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s6;
		ETHERNET10T1S_SETTINGS t1s6;
		ETHERNET10T1S_SETTINGS_EXT t1s6Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s7;
		ETHERNET10T1S_SETTINGS t1s7;
		ETHERNET10T1S_SETTINGS_EXT t1s7Ext;
		// 10T1S
		ETHERNET_SETTINGS2 ethT1s8;
		ETHERNET10T1S_SETTINGS t1s8;
		ETHERNET10T1S_SETTINGS_EXT t1s8Ext;
	} radgigastar2_settings_t;
#pragma pack(pop)

#ifdef __cplusplus

	static_assert(sizeof(radgigastar2_settings_t) == 2024, "RADGigastar2 settings size mismatch");

#include <iostream>

	class RADGigastar2Settings : public IDeviceSettings
	{
	public:
		RADGigastar2Settings(std::shared_ptr<Communication> com) : IDeviceSettings(com, sizeof(radgigastar2_settings_t)) {}
		const CAN_SETTINGS *getCANSettingsFor(Network net) const override
		{
			auto cfg = getStructurePointer<radgigastar2_settings_t>();
			if (cfg == nullptr)
				return nullptr;
			switch (net.getNetID())
			{
			case Network::NetID::HSCAN:
				return &(cfg->can1);
			case Network::NetID::HSCAN2:
				return &(cfg->can2);
			case Network::NetID::HSCAN3:
				return &(cfg->can3);
			case Network::NetID::HSCAN4:
				return &(cfg->can4);
			default:
				return nullptr;
			}
		}
		const CANFD_SETTINGS *getCANFDSettingsFor(Network net) const override
		{
			auto cfg = getStructurePointer<radgigastar2_settings_t>();
			if (cfg == nullptr)
				return nullptr;
			switch (net.getNetID())
			{
			case Network::NetID::HSCAN:
				return &(cfg->canfd1);
			case Network::NetID::HSCAN2:
				return &(cfg->canfd2);
			case Network::NetID::HSCAN3:
				return &(cfg->canfd3);
			case Network::NetID::HSCAN4:
				return &(cfg->canfd4);
			default:
				return nullptr;
			}
		}

		virtual std::vector<TerminationGroup> getTerminationGroups() const override
		{
			return {
				{Network(Network::NetID::HSCAN)},
				{Network(Network::NetID::HSCAN2)},
				{Network(Network::NetID::HSCAN3)},
				{Network(Network::NetID::HSCAN4)}};
		}

		const LIN_SETTINGS *getLINSettingsFor(Network net) const override
		{
			auto cfg = getStructurePointer<radgigastar2_settings_t>();
			if (cfg == nullptr)
				return nullptr;
			switch (net.getNetID())
			{
			case Network::NetID::LIN:
				return &(cfg->lin1);
			case Network::NetID::LIN2:
				return &(cfg->lin2);
			case Network::NetID::LIN3:
				return &(cfg->lin3);
			case Network::NetID::LIN4:
				return &(cfg->lin4);
			case Network::NetID::LIN5:
				return &(cfg->lin5);
			case Network::NetID::LIN6:
				return &(cfg->lin6);
			case Network::NetID::LIN7:
				return &(cfg->lin7);
			case Network::NetID::LIN8:
				return &(cfg->lin8);
			case Network::NetID::LIN9:
				return &(cfg->lin9);
			case Network::NetID::LIN10:
				return &(cfg->lin10);
			default:
				return nullptr;
			}
		}

	protected:
		ICSNEO_UNALIGNED(const uint64_t *)
		getTerminationEnables() const override
		{
			auto cfg = getStructurePointer<radgigastar2_settings_t>();
			if (cfg == nullptr)
				return nullptr;
			return &cfg->termination_enables;
		}
	};

	typedef struct
	{
		uint8_t unused[3];
		uint8_t ethernetActivationLineEnabled;
	} radgigastar2_status_t;
}

#endif // __cplusplus

#endif