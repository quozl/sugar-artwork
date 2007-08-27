/*
 * Copyright (C) 2007, Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __SUGAR_RC_STYLE_H
#define __SUGAR_RC_STYLE_H

#include <gtk/gtkrc.h>

typedef struct _SugarRcStyle SugarRcStyle;
typedef struct _SugarRcStyleClass SugarRcStyleClass;

G_GNUC_INTERNAL extern GType sugar_type_rc_style;

/* Bit field for the engine options. */
typedef enum {
    OPTION_LINE_WIDTH       = 1 << 0,
    OPTION_THICK_LINE_WIDTH = 1 << 1,
    OPTION_MAX_RADIUS       = 1 << 2,
    OPTION_SCROLLBAR_BORDER = 1 << 3,
    OPTION_FAKE_PADDING     = 1 << 4,
    OPTION_SUBCELL_SIZE     = 1 << 5,
    OPTION_HINT             = 1 << 6,
    OPTION_LABEL_FG_COLOR   = 1 << 7
} SugarRcStyleOptions;

typedef struct {
    guint8 fg;
    guint8 bg;
    guint8 base;
    guint8 text;
} SugarColorBitfield;


#define SUGAR_TYPE_RC_STYLE              sugar_type_rc_style
#define SUGAR_RC_STYLE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), SUGAR_TYPE_RC_STYLE, SugarRcStyle))
#define SUGAR_RC_STYLE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), SUGAR_TYPE_RC_STYLE, SugarRcStyleClass))
#define SUGAR_IS_RC_STYLE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), SUGAR_TYPE_RC_STYLE))
#define SUGAR_IS_RC_STYLE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), SUGAR_TYPE_RC_STYLE))
#define SUGAR_RC_STYLE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), SUGAR_TYPE_RC_STYLE, SugarRcStyleClass))

struct _SugarRcStyle {
    GtkRcStyle parent_instance;

    SugarRcStyleOptions flags;

    gchar *hint;
    gdouble line_width;
    gdouble thick_line_width;
    gdouble max_radius;
    gdouble scrollbar_border;
    gdouble fake_padding;
    gdouble subcell_size;

    /* The purpose of this color is to be able to apply a color from
     * a different style at merge time. This cannot be done with symbolic
     * colors. */
    GdkColor label_fg_color;
    SugarColorBitfield apply_label_color;
};

struct _SugarRcStyleClass {
    GtkRcStyleClass parent_class;
};

G_GNUC_INTERNAL void sugar_rc_style_register_type (GTypeModule *module);

#endif /* __SUGAR_RC_STYLE_H */
