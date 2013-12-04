/**************************************************************************
**
** Copyright (c) 2014 Denis Mingulov
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include "classviewsymbolinformation.h"
#include "classviewutils.h"

#include <QPair>
#include <QHash>

namespace ClassView {
namespace Internal {

/*!
    \class SymbolInformation
    \brief The SymbolInformation class provides the name, type, and icon for a
    single item in the Class View tree.
*/

SymbolInformation::SymbolInformation() :
    m_iconType(INT_MIN),
    m_hash(0)
{
}

SymbolInformation::SymbolInformation(const QString &valueName, const QString &valueType,
                                     int valueIconType) :
    m_iconType(valueIconType),
    m_name(valueName),
    m_type(valueType)
{
    // calculate hash
    m_hash = qHash(qMakePair(m_iconType, qMakePair(m_name, m_type)));
}

/*!
    Returns an icon type sort order number. It is not pre-calculated, as it is
    needed for converting to standard item only.
*/

int SymbolInformation::iconTypeSortOrder() const
{
    return Utils::iconTypeSortOrder(m_iconType);
}

bool SymbolInformation::operator<(const SymbolInformation &other) const
{
    // comparsion is not a critical for speed
    if (iconType() != other.iconType()) {
        int l = iconTypeSortOrder();
        int r = other.iconTypeSortOrder();
        if (l < r)
            return true;
        if (l > r)
            return false;
    }

    int cmp = name().compare(other.name());
    if (cmp < 0)
        return true;
    if (cmp > 0)
        return false;
    return type().compare(other.type()) < 0;
}

} // namespace Internal
} // namespace ClassView
