/*=================================================================================================   Copyright (c) 2016 Joel de Guzman   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.   http://creativecommons.org/licenses/by-sa/4.0/=================================================================================================*/#if !defined(PHOTON_GUI_LIB_CONTEXT_APRIL_17_2016)#define PHOTON_GUI_LIB_CONTEXT_APRIL_17_2016#include <photon/point.hpp>#include <photon/rect.hpp>#include <photon/theme.hpp>#include <photon/canvas.hpp>// forwardstruct NVGcontext;namespace photon{	////////////////////////////////////////////////////////////////////////////////////////////////	// Contexts	////////////////////////////////////////////////////////////////////////////////////////////////   class window;   class app;   class widget;   struct basic_context   {      basic_context(window& window_)       : window(window_)      {}      basic_context(basic_context const&) = default;      basic_context& operator=(basic_context const&) = default;      point                cursor_pos() const;      class canvas&        canvas() const;      theme&               theme() const;      window&              window;   };	////////////////////////////////////////////////////////////////////////////////////////////////   struct context : basic_context   {      context(context const& rhs, rect bounds_)       : basic_context(rhs.window), widget(rhs.widget)       , parent(rhs.parent), bounds(bounds_)      {}      context(context const& parent_, widget* widget_, rect bounds_)       : basic_context(parent_.window), widget(widget_)       , parent(&parent_), bounds(bounds_)      {}      context(class window& window_, widget* widget_, rect bounds_)       : basic_context(window_), widget(widget_)       , parent(0), bounds(bounds_)      {}      context(context const&) = default;      context& operator=(context const&) = default;      widget*              widget;      context const*       parent;      rect                 bounds;   };}#endif