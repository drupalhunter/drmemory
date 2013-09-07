/* **********************************************************
 * Copyright (c) 2013 Branden Clark  All rights reserved.
 * **********************************************************/

/* Dr. Memory: the memory debugger
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License, and no later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* dhvis_factory.cpp
 * 
 * Provides the Dr. Heapstat visualizer factory
 */

#define __CLASS__ "dhvis_factory_t::"

#include <QDebug>

#include "drgui_tool_interface.h"
#include "drgui_options_interface.h"
#include "dhvis_structures.h"
#include "dhvis_tool.h"
#include "dhvis_factory.h"


/* Public
 * Constructor
 */
dhvis_factory_t::dhvis_factory_t(void) 
{
    qDebug().nospace() << "INFO: Entering " << __CLASS__ << __FUNCTION__;
    /* XXX i#1319: Create and connect options page */
    options = new dhvis_options_t;
}

/* Public
 * Destructor
 */
dhvis_factory_t::~dhvis_factory_t(void) 
{
    qDebug().nospace() << "INFO: Entering " << __CLASS__ << __FUNCTION__;
    /* XXX i#1319: Delete options page*/
    delete options;
    while (tool_instances.count() > 0) {
        dhvis_tool_t *tmp = tool_instances.back();
        tool_instances.pop_back();
        delete tmp;
    }
}

/* Public
 * Returns provided tool names during loading
 */
QStringList 
dhvis_factory_t::tool_names(void) const 
{
    qDebug().nospace() << "INFO: Entering " << __CLASS__ << __FUNCTION__;
    return QStringList() << "Dr. Heapstat";
}

/* Public
 * Returns a new instance of the tool
 */
QWidget *
dhvis_factory_t::create_instance(void) 
{
    qDebug().nospace() << "INFO: Entering " << __CLASS__ << __FUNCTION__;
    tool_instances.append(new dhvis_tool_t(options));
    return tool_instances.back();
}

/* Public
 * Refreshes and returns the options page
 */
drgui_options_interface_t *
dhvis_factory_t::create_options_page(void) 
{
    qDebug().nospace() << "INFO: Entering " << __CLASS__ << __FUNCTION__;
    /* XXX i#1319: return the options page */
    return NULL;
}

/* Public
 * Unused virtual implementation
 */
void
dhvis_factory_t::open_file(const QString &path, int line_num)
{
    Q_UNUSED(path);
    Q_UNUSED(line_num);
    qDebug().nospace() << "INFO: Entering " << __CLASS__ << __FUNCTION__;
}
