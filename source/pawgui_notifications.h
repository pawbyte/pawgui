/*
pawgui_notifications.h
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

#ifndef pawgui_notificatons_h
#define pawgui_notificatons_h

#include "pawgui_base.h"

namespace pawgui
{
    class widget_notifcation: public widget_basic
    {
        protected:
            std::string notification_text;
            std::string notification_url;
            gpe::texture_base * notification_icon;
        public:
            bool remove_requested;
            widget_notifcation(std::string name_param, std::string description = "");
            ~widget_notifcation();
            std::string get_data();
            std::string get_plain_string();
            void load_data(std::string dataString);
            void process_self( gpe::shape_rect * view_space = NULL, gpe::shape_rect * cam = NULL);
            void render_self( gpe::shape_rect * view_space = NULL, gpe::shape_rect * cam = NULL);
            void set_name(std::string name_param);
    };

    class widget_notfications_holder: public widget_basic
    {
        public:
            int notifications_in_view_max;
            std::vector < widget_notifcation* > notifications;
            widget_notfications_holder();
            ~widget_notfications_holder();
            widget_notifcation * add_notification( std::string name, std::string description);
            bool remove_notification( std::string name );
            void process_self( gpe::shape_rect * view_space = NULL, gpe::shape_rect * cam = NULL);
            void render_self( gpe::shape_rect * view_space = NULL, gpe::shape_rect * cam = NULL);
    };
}

#endif //pawgui_notificatons_h
