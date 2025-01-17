#include "ut_theme_proxy.h"

#include "view/theme_proxy.h"
#include <DGuiApplicationHelper>



ut_theme_proxy_test::ut_theme_proxy_test()
{

}

TEST_F(ut_theme_proxy_test, getTheme)
{
    ThemeProxy tp;

    DTK_GUI_NAMESPACE::DGuiApplicationHelper::instance()->setThemeType(DTK_GUI_NAMESPACE::DGuiApplicationHelper::LightType);
    ASSERT_EQ(tp.getTheme(), "LightType");

    DTK_GUI_NAMESPACE::DGuiApplicationHelper::instance()->setThemeType(DTK_GUI_NAMESPACE::DGuiApplicationHelper::DarkType);
    ASSERT_EQ(tp.getTheme(), "DarkType");


}

TEST_F(ut_theme_proxy_test, slot_ThemeChange)
{
    ThemeProxy tp;

    tp.slot_ThemeChange();
}

