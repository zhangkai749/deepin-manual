/*
* Copyright (C) 2019 ~ 2020 Deepin Technology Co., Ltd.
*
* Author:     wangmingliang <wangmingliang@uniontech.com>
* Maintainer: wangmingliang <wanmgmingliang@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "ut_search_completion_listview.h"

#include "view/widget/search_completion_listview.h"

ut_search_completion_listview_test::ut_search_completion_listview_test()
{

}

TEST_F(ut_search_completion_listview_test, initDelegate)
{
    SearchCompletionListView sv;
    sv.initDelegate();
    ASSERT_TRUE(sv.m_searchCompletionDelegate);
}


TEST_F(ut_search_completion_listview_test, mousePressEvent)
{

    SearchCompletionListView sv;
    QMouseEvent *evnPressEnter;
    evnPressEnter = new QMouseEvent( QEvent::MouseButtonPress, QPoint(0, 0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier );
    sv.mousePressEvent(evnPressEnter);
    ASSERT_TRUE(sv.m_bLeftMouse);
    delete evnPressEnter;

    evnPressEnter = new QMouseEvent( QEvent::MouseButtonPress, QPoint(0, 0), Qt::RightButton, Qt::NoButton, Qt::NoModifier );
    sv.mousePressEvent(evnPressEnter);
    ASSERT_FALSE(sv.m_bLeftMouse);
    delete evnPressEnter;
}

TEST_F(ut_search_completion_listview_test, mousePressEvent2)
{
    SearchCompletionListView sv;
    QTest::mouseClick(sv.window(), Qt::LeftButton);
    ASSERT_FALSE(sv.m_bLeftMouse);
    QTest::mouseClick(sv.window(), Qt::RightButton);
    ASSERT_FALSE(sv.m_bLeftMouse);
}

TEST_F(ut_search_completion_listview_test, setSelection)
{

    SearchCompletionListView *sv = new SearchCompletionListView();
    QRect rect;
    QItemSelectionModel::SelectionFlags command;
    sv->m_bLeftMouse = true;
    sv->setSelection(rect, command);
    sv->m_bLeftMouse = false;
    sv->setSelection(rect, command);

}


TEST_F(ut_search_completion_listview_test, paintEvent)
{

    SearchCompletionListView *sv = new SearchCompletionListView();
    QRect rect;
    QPaintEvent *event = new QPaintEvent(rect);
    sv->paintEvent(event);
    delete event;

}
