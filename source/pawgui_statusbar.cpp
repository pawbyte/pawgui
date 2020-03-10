/*
pawgui_statusbar.cpp
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
#include "pawgui_statusbar.h"

namespace pawgui
{
    widget_statusbar * main_statusbar = NULL;

    widget_statusbar::widget_statusbar()
    {
        widget_box.h = 24;
        guiListTypeName = "statusbar";
        codeEditorStatusBarString = "";
        insertModeString = "";
    }

    widget_statusbar::~widget_statusbar()
    {

    }

    void widget_statusbar::process_self( gpe::shape_rect * viewedSpace, gpe::shape_rect *cam)
    {
        codeEditorStatusBarString= "";
        insertModeString = "";
    }

    void widget_statusbar::render_self( gpe::shape_rect * viewedSpace, gpe::shape_rect *cam)
    {
        if( isEnabled&& widget_box.h >0 && FONT_STATUSBAR!=NULL)
        {
            gpe::gcanvas->render_rect( &widget_box,theme_main->program_color,false);
            int statusBarStringWidth = 0, statusBarStringHeight = 0;
            int projectNameWidth = 0, projectNameHeight = 0;
            if( (int)statusBarLeftText.size() > 0)
            {
                std::string  projectNameToRender = statusBarLeftText;
                if( sff_ex::file_exists( statusBarLeftText) )
                {
                    if( main_settings && main_settings->useShortProjectNames )
                    {
                        projectNameToRender = stg_ex::get_file_noext( stg_ex::get_local_from_global_file(statusBarLeftText) );
                    }
                }
                FONT_STATUSBAR->get_metrics(projectNameToRender,&projectNameWidth, &projectNameHeight);

                if( (int)codeEditorStatusBarString.size() > 0)
                {
                    FONT_STATUSBAR->get_numbered_metrics(codeEditorStatusBarString,&statusBarStringWidth, &statusBarStringHeight);
                    if( widget_box.w > statusBarStringWidth+projectNameWidth +GENERAL_GPE_GUI_PADDING )
                    {
                        gpe::gfs->render_text( widget_box.x,widget_box.y+widget_box.h/2,projectNameToRender,theme_main->main_box_font_color,FONT_STATUSBAR, gpe::fa_left, gpe::fa_middle);
                        //gpe::gcanvas->render_rectangle( widget_box.x+projectNameWidth,widget_box.y,widget_box.x+widget_box.w,widget_box.y+widget_box.h,theme_main->button_box_color,false);
                        gpe::gfs->render_text( widget_box.x+projectNameWidth+GENERAL_GPE_GUI_PADDING,widget_box.y+widget_box.h/2,codeEditorStatusBarString,theme_main->main_box_font_color,FONT_STATUSBAR,gpe::fa_left,gpe::fa_middle);
                    }
                    else
                    {
                        gpe::gfs->render_text( widget_box.x+GENERAL_GPE_GUI_PADDING,widget_box.y+widget_box.h/2,codeEditorStatusBarString,theme_main->main_box_font_color,FONT_STATUSBAR, gpe::fa_left, gpe::fa_middle);
                    }
                }
                else if( widget_box.w > projectNameWidth +GENERAL_GPE_GUI_PADDING )
                {
                    gpe::gfs->render_text( widget_box.x+GENERAL_GPE_GUI_PADDING,widget_box.y+widget_box.h/2,projectNameToRender,theme_main->main_box_font_color,FONT_STATUSBAR, gpe::fa_left, gpe::fa_middle);
                }
                else
                {
                    gpe::gfs->render_text( widget_box.x+widget_box.w-GENERAL_GPE_GUI_PADDING/2,widget_box.y+widget_box.h/2,projectNameToRender,theme_main->main_box_font_color,FONT_STATUSBAR, gpe::fa_right, gpe::fa_middle);
                }
            }
            else if( (int)codeEditorStatusBarString.size() > 0)
            {
                FONT_STATUSBAR->get_numbered_metrics(codeEditorStatusBarString,&statusBarStringWidth, &statusBarStringHeight);
                gpe::gfs->render_text( widget_box.x+GENERAL_GPE_GUI_PADDING,widget_box.y+widget_box.h/2,codeEditorStatusBarString,theme_main->main_box_font_color,FONT_STATUSBAR, gpe::fa_left, gpe::fa_middle );
            }
            gpe::gcanvas->render_rect( &widget_box,theme_main->main_border_color,true);
        }
    }

    void widget_statusbar::reset_statusbar()
    {
        codeEditorStatusBarString = "";
        insertModeString = "";
    }

    void widget_statusbar::set_codestring(std::string newCodeString)
    {
        codeEditorStatusBarString = newCodeString;
    }

    void widget_statusbar::set_insertmode(std::string newInsertMode)
    {
        insertModeString = newInsertMode;
    }
}
