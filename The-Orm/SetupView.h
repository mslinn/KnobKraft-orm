/*
   Copyright (c) 2020 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "JuceHeader.h"

//#include "HueLightControl.h"
#include "PropertyEditor.h"
#include "LambdaButtonStrip.h"

#include "AutoDetection.h"

class SetupView : public Component,
	private ChangeListener
{
public:
	SetupView(midikraft::AutoDetection *autoDetection /*, HueLightControl *lights*/);
	virtual ~SetupView();

	virtual void resized() override;
	virtual void changeListenerCallback(ChangeBroadcaster* source) override;

	void refreshData();

private:
	std::vector<std::string> currentOutputDevices() const;
	std::vector<std::string> currentInputDevices() const;

	int indexOfOutputDevice(std::string const &outputDevice) const;
	int indexOfInputDevice(std::string const &inputDevice) const;

	std::vector<std::shared_ptr<TypedNamedValue>> properties_;
	std::map<int, std::string> inputLookup_;
	std::map<int, std::string> outputLookup_;
	midikraft::AutoDetection *autoDetection_;
	//HueLightControl * lights_;
	LambdaButtonStrip functionButtons_;
	PropertyEditor propertyEditor_;
};

