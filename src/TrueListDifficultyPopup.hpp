#pragma once

using namespace geode::prelude;

class TrueListDifficultyPopup : public geode::Popup<std::string const&> {
protected:
    inline bool setup(std::string const& value) override {
        // convenience function provided by Popup
        // for adding/setting a title to the popup
        this->setTitle("Hi mom!");

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        m_mainLayer->addChildAtPosition(label, Anchor::Center);

        return true;
    }
public:
    inline static TrueListDifficultyPopup* create(std::string const& text) {
        auto ret = new TrueListDifficultyPopup();
        if (ret->initAnchored(240.f, 160.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};