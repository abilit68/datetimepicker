/**
 * This code was generated by "react-native codegen-lib-harmony"
 */

#pragma once

#include <react/renderer/components/datetimepicker/ComponentDescriptors.h>
#include "RNOH/Package.h"
#include "RNOH/ArkTSTurboModule.h"
#include "RNOH/generated/components/RNDateTimePickerViewJSIBinder.h"

namespace rnoh {

class BaseDatetimepickerPackageTurboModuleFactoryDelegate : public TurboModuleFactoryDelegate {
  public:
    SharedTurboModule createTurboModule(Context ctx, const std::string &name) const override {
        return nullptr;
    };
};

class BaseDatetimepickerPackageEventEmitRequestHandler : public EventEmitRequestHandler {
  public:
    void handleEvent(Context const &ctx) override {
        auto eventEmitter = ctx.shadowViewRegistry->getEventEmitter<facebook::react::EventEmitter>(ctx.tag);
        if (eventEmitter == nullptr) {
            return;
        }

        std::vector<std::string> supportedEventNames = {
            "change",
            "pickerDismiss",
        };
        if (std::find(supportedEventNames.begin(), supportedEventNames.end(), ctx.eventName) != supportedEventNames.end()) {
            eventEmitter->dispatchEvent(ctx.eventName, ArkJS(ctx.env).getDynamic(ctx.payload));
        }    
    }
};


class BaseDatetimepickerPackage : public Package {
  public:
    BaseDatetimepickerPackage(Package::Context ctx) : Package(ctx){};

    std::unique_ptr<TurboModuleFactoryDelegate> createTurboModuleFactoryDelegate() override {
        return std::make_unique<BaseDatetimepickerPackageTurboModuleFactoryDelegate>();
    }

    std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
        return {
            facebook::react::concreteComponentDescriptorProvider<facebook::react::RNDateTimePickerViewComponentDescriptor>(),
        };
    }

    ComponentJSIBinderByString createComponentJSIBinderByName() override {
        return {
            {"RNDateTimePickerView", std::make_shared<RNDateTimePickerViewJSIBinder>()},
        };
    };

    EventEmitRequestHandlers createEventEmitRequestHandlers() override {
        return {
            std::make_shared<BaseDatetimepickerPackageEventEmitRequestHandler>(),
        };
    }
};

} // namespace rnoh
