/*
pawgui_notifications.cpp
This file is part of:
PawByte Ambitious Working GUI(PAWGUI)
https://www.pawbyte.com/pawgui
Copyright (c) 2014-2020 Nathan Hurde, Chase Lee.

Copyright (c) 2014-2020 PawByte LLC.
Copyright (c) 2014-2020 PawByte Ambitious Working GUI(PAWGUI) contributors ( Contributors Page )

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-PawByte Ambitious Working GUI(PAWGUI) <https://www.pawbyte.com/pawgui>


*/

#include "pawgui_notifications.h"

namespace pawgui
{
    widget_notifcation::widget_notifcation(std::string name_param, std::string description )
    {
        remove_requested = false;

    }

    widget_notifcation::~widget_notifcation()
    {

    }

    std::string widget_notifcation::get_data()
    {
        return "";
    }

    std::string widget_notifcation::get_plain_string()
    {
        return "";
    }

    void widget_notifcation::load_data(std::string dataString)
    {

    }

    void widget_notifcation::process_self( gpe::shape_rect * view_space, gpe::shape_rect * cam )
    {
        remove_requested = false;
    }

    void widget_notifcation::render_self( gpe::shape_rect * view_space, gpe::shape_rect * cam )
    {

    }

    void widget_notifcation::set_name(std::string name_param)
    {

    }

    widget_notfications_holder::widget_notfications_holder()
    {
        notifications_in_view_max  = 3;
    }

    widget_notfications_holder::~widget_notfications_holder()
    {

    }

    void widget_notfications_holder::process_self( gpe::shape_rect * view_space, gpe::shape_rect * cam )
    {
        widget_notifcation * temp_notification = NULL;
        int iMin = std::max( 0, (int)notifications.size() - notifications_in_view_max );
        int temp_y_pos = get_ypos();
        int notification_being_removed = -1;
        for( int i = (int)notifications.size() -1; i>=iMin; i-- )
        {
            temp_notification = notifications[i];
            if( temp_notification != NULL )
            {
                temp_notification->set_width( get_width() );
                temp_notification->set_coords( get_xpos(), temp_y_pos );
                temp_notification->process_self( view_space, cam );
                temp_y_pos += temp_notification->get_height();
                if( temp_notification->remove_requested )
                {
                    notification_being_removed = i;
                }
            }
        }
        if( notification_being_removed >=0 )
        {
            temp_notification = notifications[ notification_being_removed];
            if( temp_notification !=NULL )
            {
                delete temp_notification;
                temp_notification = NULL;
            }
            notifications.erase( notifications.begin() + notification_being_removed );
        }
    }

    void widget_notfications_holder::render_self( gpe::shape_rect * view_space, gpe::shape_rect * cam )
    {
        widget_notifcation * temp_notification = NULL;
        int iMin = std::max( 0, (int)notifications.size() - notifications_in_view_max );
        int temp_y_pos = get_ypos();
        for( int i = (int)notifications.size() -1; i>=iMin; i-- )
        {
            temp_notification = notifications[i];
            if( temp_notification != NULL )
            {
                temp_notification->set_coords( get_xpos(), temp_y_pos );
                temp_notification->render_self( view_space, cam );
                temp_y_pos += temp_notification->get_height();
            }
        }
    }
}
