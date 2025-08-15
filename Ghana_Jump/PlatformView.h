#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

#include "EntityView.h"
#include <memory>
#include "Platform.h"
#include "StaticPlatform.h"
#include "GrayPlatform.h"
#include "HorizontalPlatform.h"
#include "VerticalPlatform.h"

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class PlatformView
         * @brief De visuele representatie voor alle soorten platformen.
         *
         * Deze klasse laadt de correcte texture gebaseerd op het dynamische type
         * van het platform-object en is verantwoordelijk voor het tekenen ervan.
         */
        class PlatformView : public EntityView {
        private:
            std::shared_ptr<Entities::Platform> platform; // Pointer naar platform als entiteit
            sf::Texture texture; // Texture, hangt af van type platform
        public:
            PlatformView(std::shared_ptr<Entities::Platform> platform); // Regel van drie
            ~PlatformView() override = default;
            PlatformView(const PlatformView&) = default;
            PlatformView& operator=(const PlatformView&) = default;

            void render(sf::RenderWindow& window) override; // Override van EntityView
            void update(float cameraY) override; // Override van Observer
            std::shared_ptr<Entities::Platform> getPlatform() const; // Getter
        };
    }
}

#endif //PLATFORMVIEW_H


