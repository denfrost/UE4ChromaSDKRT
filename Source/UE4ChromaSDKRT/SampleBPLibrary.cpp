// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

//#include "SampleBPLibrary.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "UE4ChromaSDKRT.h"
#include "SampleBPLibrary.h" //___HACK_UE4_VERSION_4_15_OR_LESS
#include "ChromaSDKPluginBPLibrary.h"

float USampleBPLibrary::_sBaseIntensity = 1.0f;
float USampleBPLibrary::_sEffectIntensity = 1.0f;
float USampleBPLibrary::_sHotkeyIntensity = 1.0f;
int USampleBPLibrary::_sSelectedLayerExample = 0;

USampleBPLibrary::USampleBPLibrary(const FPostConstructInitializeProperties& PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
	: Super(PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
//USampleBPLibrary::USampleBPLibrary(const FObjectInitializer& ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
//	: Super(ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
{
}

void USampleBPLibrary::SampleStart()
{
	UChromaSDKPluginBPLibrary::ChromaSDKInit();
}

void USampleBPLibrary::SampleEnd()
{
	UChromaSDKPluginBPLibrary::ChromaSDKUnInit();
}

void USampleBPLibrary::SamplePlayComposite()
{
	UChromaSDKPluginBPLibrary::PlayAnimationComposite("Random", false);
}

void USampleBPLibrary::SamplePlayCompositeLoop()
{
	UChromaSDKPluginBPLibrary::PlayAnimationComposite("Random", true);
}

void USampleBPLibrary::SampleStopComposite()
{
	UChromaSDKPluginBPLibrary::StopAnimationComposite("Random");
}

void USampleBPLibrary::SampleClearComposite()
{
	UChromaSDKPluginBPLibrary::ClearAll();
}

void USampleBPLibrary::SampleShowHotkeysAnimated()
{
	TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys = TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>();
	keys.Add(EChromaSDKKeyboardKey::KK_W);
	keys.Add(EChromaSDKKeyboardKey::KK_A);
	keys.Add(EChromaSDKKeyboardKey::KK_S);
	keys.Add(EChromaSDKKeyboardKey::KK_D);
	keys.Add(EChromaSDKKeyboardKey::KK_LOGO);
	keys.Add(EChromaSDKKeyboardKey::KK_ESC);

	FString target = "Random_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(target);

	FString source = "Fire_Keyboard";
	UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(source, target, keys);

	UChromaSDKPluginBPLibrary::PlayAnimation(target, true);
}

void USampleBPLibrary::SampleShowHotkeysStaticColor()
{
	TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys = TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>();
	keys.Add(EChromaSDKKeyboardKey::KK_W);
	keys.Add(EChromaSDKKeyboardKey::KK_A);
	keys.Add(EChromaSDKKeyboardKey::KK_S);
	keys.Add(EChromaSDKKeyboardKey::KK_D);
	keys.Add(EChromaSDKKeyboardKey::KK_LOGO);
	keys.Add(EChromaSDKKeyboardKey::KK_ESC);

	FString target = "Random_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(target);

	FLinearColor color = FLinearColor(1, 0, 0, 0);
	UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(target, keys, color);

	UChromaSDKPluginBPLibrary::PlayAnimation(target, true);
}

void USampleBPLibrary::SampleHideHotkeys()
{
	FString animation = "Random_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(animation);
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SamplePlayAnimationChromaLink()
{
	FString animation = "Fire_ChromaLink";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, false);
}

void USampleBPLibrary::SamplePlayAnimationHeadset()
{
	FString animation = "Fire_Headset";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, false);
}

void USampleBPLibrary::SamplePlayAnimationKeyboard()
{
	FString animation = "Fire_Keyboard";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, false);
}

void USampleBPLibrary::SamplePlayAnimationKeypad()
{
	FString animation = "Fire_Keypad";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, false);
}

void USampleBPLibrary::SamplePlayAnimationMouse()
{
	FString animation = "Fire_Mouse";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, false);
}

void USampleBPLibrary::SamplePlayAnimationMousepad()
{
	FString animation = "Fire_Mousepad";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, false);
}

void USampleBPLibrary::SampleLoopAnimationChromaLink()
{
	FString animation = "Fire_ChromaLink";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SampleLoopAnimationHeadset()
{
	FString animation = "Fire_Headset";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SampleLoopAnimationKeyboard()
{
	FString animation = "Fire_Keyboard";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SampleLoopAnimationKeypad()
{
	FString animation = "Fire_Keypad";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SampleLoopAnimationMouse()
{
	FString animation = "Fire_Mouse";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SampleLoopAnimationMousepad()
{
	FString animation = "Fire_Mousepad";
	UChromaSDKPluginBPLibrary::PlayAnimation(animation, true);
}

void USampleBPLibrary::SampleStopAnimationChromaLink()
{
	FString animation = "Fire_ChromaLink";
	UChromaSDKPluginBPLibrary::StopAnimation(animation);
}

void USampleBPLibrary::SampleStopAnimationHeadset()
{
	FString animation = "Fire_Headset";
	UChromaSDKPluginBPLibrary::StopAnimation(animation);
}

void USampleBPLibrary::SampleStopAnimationKeyboard()
{
	FString animation = "Fire_Keyboard";
	UChromaSDKPluginBPLibrary::StopAnimation(animation);
}

void USampleBPLibrary::SampleStopAnimationKeypad()
{
	FString animation = "Fire_Keypad";
	UChromaSDKPluginBPLibrary::StopAnimation(animation);
}

void USampleBPLibrary::SampleStopAnimationMouse()
{
	FString animation = "Fire_Mouse";
	UChromaSDKPluginBPLibrary::StopAnimation(animation);
}

void USampleBPLibrary::SampleStopAnimationMousepad()
{
	FString animation = "Fire_Mousepad";
	UChromaSDKPluginBPLibrary::StopAnimation(animation);
}

void USampleBPLibrary::SampleStaticColorChromaLink()
{
	UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::DE_ChromaLink);
	FLinearColor color = FLinearColor(1, 0, 0);
	FChromaSDKEffectResult result = UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::DE_ChromaLink, color);
	UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(result.EffectId);
	UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(result.EffectId);
}

void USampleBPLibrary::SampleStaticColorHeadset()
{
	UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::DE_Headset);
	FLinearColor color = FLinearColor(1, 1, 0);
	FChromaSDKEffectResult result = UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::DE_Headset, color);
	UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(result.EffectId);
	UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(result.EffectId);
}

void USampleBPLibrary::SampleStaticColorKeyboard()
{
	UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::DE_Keyboard);
	FLinearColor color = FLinearColor(1, 0, 1);
	FChromaSDKEffectResult result = UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::DE_Keyboard, color);
	UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(result.EffectId);
	UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(result.EffectId);
}

void USampleBPLibrary::SampleStaticColorKeypad()
{
	UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::DE_Keypad);
	FLinearColor color = FLinearColor(0, 1, 1);
	FChromaSDKEffectResult result = UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::DE_Keypad, color);
	UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(result.EffectId);
	UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(result.EffectId);
}

void USampleBPLibrary::SampleStaticColorMouse()
{
	UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::DE_Mouse);
	FLinearColor color = FLinearColor(1, 1, 1);
	FChromaSDKEffectResult result = UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::DE_Mouse, color);
	UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(result.EffectId);
	UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(result.EffectId);
}

void USampleBPLibrary::SampleStaticColorMousepad()
{
	UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::DE_Mousepad);
	FLinearColor color = FLinearColor(1, 0.5f, 0);
	FChromaSDKEffectResult result = UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::DE_Mousepad, color);
	UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(result.EffectId);
	UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(result.EffectId);
}

void USampleBPLibrary::SampleClearChromaLink()
{
	UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::DE_ChromaLink);
}

void USampleBPLibrary::SampleClearHeadset()
{
	UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::DE_Headset);
}

void USampleBPLibrary::SampleClearKeyboard()
{
	UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::DE_Keyboard);
}

void USampleBPLibrary::SampleClearKeypad()
{
	UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::DE_Keypad);
}

void USampleBPLibrary::SampleClearMouse()
{
	UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::DE_Mouse);
}

void USampleBPLibrary::SampleClearMousepad()
{
	UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::DE_Mousepad);
}

void USampleBPLibrary::SampleLayeredHeal()
{
	_sSelectedLayerExample = 0;

	TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys = TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>();
	keys.Add(EChromaSDKKeyboardKey::KK_LOGO);
	keys.Add(EChromaSDKKeyboardKey::KK_ESC);
	keys.Add(EChromaSDKKeyboardKey::KK_Q);
	keys.Add(EChromaSDKKeyboardKey::KK_E);

	FString baseLayer = "EnvironmentSnow_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(baseLayer);
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(baseLayer, 1.0f + 64.0f * _sBaseIntensity);

	FString layer2 = "RingGray_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(layer2);
	// turn animation green
	UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(layer2, -127, 127, -127); //animation starts with 127,127,127 so adding -127,127,-127 results in 0,255,0 or green
	// set intensity
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(layer2, _sEffectIntensity);
	UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesName(layer2, baseLayer);

	FString layer3 = "FadeInOutGray_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(layer3);
	// change color
	UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(layer3, 173-127, 255-127, 47-127);
	// set intensity
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(layer3, _sHotkeyIntensity);
	UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(layer3, baseLayer, keys);

	keys.Reset();
	keys.Add(EChromaSDKKeyboardKey::KK_W);
	keys.Add(EChromaSDKKeyboardKey::KK_A);
	keys.Add(EChromaSDKKeyboardKey::KK_S);
	keys.Add(EChromaSDKKeyboardKey::KK_D);

	FLinearColor color = FLinearColor(_sHotkeyIntensity * 1, _sHotkeyIntensity * 0.5f, 0, 0);
	UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(baseLayer, keys, color);

	UChromaSDKPluginBPLibrary::PlayAnimation(baseLayer, true);
}

void USampleBPLibrary::SampleLayeredDamage()
{
	_sSelectedLayerExample = 1;

	TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys = TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>();
	keys.Add(EChromaSDKKeyboardKey::KK_LOGO);
	keys.Add(EChromaSDKKeyboardKey::KK_ESC);
	keys.Add(EChromaSDKKeyboardKey::KK_Q);
	keys.Add(EChromaSDKKeyboardKey::KK_E);

	FString baseLayer = "EnvironmentSnow_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(baseLayer);
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(baseLayer, 1.0f + 64.0f * _sBaseIntensity);

	FString layer2 = "RingGray_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(layer2);
	// turn animation red
	UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(layer2, 127, -127, -127); //animation starts with 127,127,127 so adding 127,-127,-127 results in 255,0,0 or red
	// set intensity
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(layer2, _sEffectIntensity);
	UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesName(layer2, baseLayer);

	FString layer3 = "FadeInOutGray_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(layer3);
	// change color
	UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(layer3, 220-127, 20-127, 60-127);
	// set intensity
	UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(layer3, baseLayer, keys);

	keys.Reset();
	keys.Add(EChromaSDKKeyboardKey::KK_W);
	keys.Add(EChromaSDKKeyboardKey::KK_A);
	keys.Add(EChromaSDKKeyboardKey::KK_S);
	keys.Add(EChromaSDKKeyboardKey::KK_D);

	FLinearColor color = FLinearColor(_sHotkeyIntensity * 1, _sHotkeyIntensity * 0.5f, 0, 0);
	UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(baseLayer, keys, color);

	UChromaSDKPluginBPLibrary::PlayAnimation(baseLayer, true);
}

void USampleBPLibrary::SampleLayeredItemPickup()
{
	_sSelectedLayerExample = 2;

	TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys = TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>();
	keys.Add(EChromaSDKKeyboardKey::KK_LOGO);
	keys.Add(EChromaSDKKeyboardKey::KK_ESC);
	keys.Add(EChromaSDKKeyboardKey::KK_Q);
	keys.Add(EChromaSDKKeyboardKey::KK_E);

	FString baseLayer = "EnvironmentSnow_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(baseLayer);
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(baseLayer, 1.0f + 64.0f * _sBaseIntensity);

	FString layer2 = "RingGray_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(layer2);
	// turn animation blue
	UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(layer2, -127, -127, 127); //animation starts with 127,127,127 so adding -127,-127,127 results in 0,0,255 or blue
	// set intensity
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(layer2, _sEffectIntensity);
	UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesName(layer2, baseLayer);

	FString layer3 = "FadeInOutGray_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(layer3);
	// change color
	UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(layer3, 64-127, 224-127, 208-127);
	// set intensity
	UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(layer3, _sHotkeyIntensity);
	UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(layer3, baseLayer, keys);

	keys.Reset();
	keys.Add(EChromaSDKKeyboardKey::KK_W);
	keys.Add(EChromaSDKKeyboardKey::KK_A);
	keys.Add(EChromaSDKKeyboardKey::KK_S);
	keys.Add(EChromaSDKKeyboardKey::KK_D);

	FLinearColor color = FLinearColor(_sHotkeyIntensity * 1, _sHotkeyIntensity * 0.5f, 0, 0);
	UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(baseLayer, keys, color);

	UChromaSDKPluginBPLibrary::PlayAnimation(baseLayer, true);
}

void USampleBPLibrary::SampleLayeredOff()
{
	FString baseLayer = "EnvironmentSnow_Keyboard";
	UChromaSDKPluginBPLibrary::CloseAnimationName(baseLayer);

	UChromaSDKPluginBPLibrary::ClearAll();
}

void USampleBPLibrary::SetupLastLayeredExample()
{
	switch (_sSelectedLayerExample)
	{
	case 0:
		SampleLayeredHeal();
		return;
	case 1:
		SampleLayeredDamage();
		return;
	case 2:
		SampleLayeredItemPickup();
		return;
	}
}

void USampleBPLibrary::SampleChangeBaseIntensity(float intensity)
{
	_sBaseIntensity = intensity;
	SetupLastLayeredExample();
}

void USampleBPLibrary::SampleChangeEffectIntensity(float intensity)
{
	_sEffectIntensity = intensity;
	SetupLastLayeredExample();
}

void USampleBPLibrary::SampleChangeHotkeyIntensity(float intensity)
{
	_sHotkeyIntensity = intensity;
	SetupLastLayeredExample();
}
