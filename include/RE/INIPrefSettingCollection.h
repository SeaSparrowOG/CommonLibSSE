#pragma once

#include "RE/INISettingCollection.h"  // INISettingCollection


namespace RE
{
	class INIPrefSettingCollection : public INISettingCollection
	{
	public:
		virtual ~INIPrefSettingCollection();	// 00

		// override (INISettingCollection)
		virtual void	Unk_07(void) override;	// 07 - { return 1; }
		virtual void	Unk_08(void) override;	// 08
		virtual void	Unk_09(void) override;	// 09

		static INIPrefSettingCollection* GetSingleton();
	};
	STATIC_ASSERT(sizeof(INIPrefSettingCollection) == 0x128);
}