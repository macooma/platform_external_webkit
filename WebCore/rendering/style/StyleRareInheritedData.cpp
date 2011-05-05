/*
 * Copyright (C) 1999 Antti Koivisto (koivisto@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"
#include "StyleRareInheritedData.h"

#include "RenderStyle.h"
#include "RenderStyleConstants.h"

namespace WebCore {

StyleRareInheritedData::StyleRareInheritedData()
    : textStrokeWidth(RenderStyle::initialTextStrokeWidth())
#ifdef ANDROID_CSS_RING
    , ringFillColor(RenderStyle::initialRingFillColor())
    , ringInnerWidth(RenderStyle::initialRingInnerWidth())
    , ringOuterWidth(RenderStyle::initialRingOuterWidth())
    , ringOutset(RenderStyle::initialRingOutset())
    , ringPressedInnerColor(RenderStyle::initialRingPressedInnerColor())
    , ringPressedOuterColor(RenderStyle::initialRingPressedOuterColor())
    , ringRadius(RenderStyle::initialRingRadius())
    , ringSelectedInnerColor(RenderStyle::initialRingSelectedInnerColor())
    , ringSelectedOuterColor(RenderStyle::initialRingSelectedOuterColor())
#endif
#ifdef ANDROID_CSS_TAP_HIGHLIGHT_COLOR
    , tapHighlightColor(RenderStyle::initialTapHighlightColor())
#endif
    , textShadow(0)
    , indent(RenderStyle::initialTextIndent())
    , m_effectiveZoom(RenderStyle::initialZoom())
    , widows(RenderStyle::initialWidows())
    , orphans(RenderStyle::initialOrphans())
    , textSecurity(RenderStyle::initialTextSecurity())
    , userModify(READ_ONLY)
    , wordBreak(RenderStyle::initialWordBreak())
    , wordWrap(RenderStyle::initialWordWrap())
    , nbspMode(NBNORMAL)
    , khtmlLineBreak(LBNORMAL)
    , textSizeAdjust(RenderStyle::initialTextSizeAdjust())
    , resize(RenderStyle::initialResize())
    , userSelect(RenderStyle::initialUserSelect())
    , colorSpace(ColorSpaceDeviceRGB)
    , speak(SpeakNormal)
    , hyphens(HyphensManual)
    , textEmphasisFill(TextEmphasisFillFilled)
    , textEmphasisMark(TextEmphasisMarkNone)
    , textEmphasisPosition(TextEmphasisPositionOver)
{
}

StyleRareInheritedData::StyleRareInheritedData(const StyleRareInheritedData& o)
    : RefCounted<StyleRareInheritedData>()
    , textStrokeColor(o.textStrokeColor)
    , textStrokeWidth(o.textStrokeWidth)
    , textFillColor(o.textFillColor)
    , textEmphasisColor(o.textEmphasisColor)
#ifdef ANDROID_CSS_RING
    , ringFillColor(o.ringFillColor)
    , ringInnerWidth(o.ringInnerWidth)
    , ringOuterWidth(o.ringOuterWidth)
    , ringOutset(o.ringOutset)
    , ringPressedInnerColor(o.ringPressedInnerColor)
    , ringPressedOuterColor(o.ringPressedOuterColor)
    , ringRadius(o.ringRadius)
    , ringSelectedInnerColor(o.ringSelectedInnerColor)
    , ringSelectedOuterColor(o.ringSelectedOuterColor)
#endif
#ifdef ANDROID_CSS_TAP_HIGHLIGHT_COLOR
    , tapHighlightColor(o.tapHighlightColor)
#endif
    , textShadow(o.textShadow ? new ShadowData(*o.textShadow) : 0)
    , highlight(o.highlight)
    , cursorData(o.cursorData)
    , indent(o.indent)
    , m_effectiveZoom(o.m_effectiveZoom)
    , widows(o.widows)
    , orphans(o.orphans)
    , textSecurity(o.textSecurity)
    , userModify(o.userModify)
    , wordBreak(o.wordBreak)
    , wordWrap(o.wordWrap)
    , nbspMode(o.nbspMode)
    , khtmlLineBreak(o.khtmlLineBreak)
    , textSizeAdjust(o.textSizeAdjust)
    , resize(o.resize)
    , userSelect(o.userSelect)
    , colorSpace(o.colorSpace)
    , speak(o.speak)
    , hyphens(o.hyphens)
    , textEmphasisFill(o.textEmphasisFill)
    , textEmphasisMark(o.textEmphasisMark)
    , textEmphasisPosition(o.textEmphasisPosition)
    , hyphenationString(o.hyphenationString)
    , hyphenationLocale(o.hyphenationLocale)
    , textEmphasisCustomMark(o.textEmphasisCustomMark)
{
}

StyleRareInheritedData::~StyleRareInheritedData()
{
    delete textShadow;
}

static bool cursorDataEquivalent(const CursorList* c1, const CursorList* c2)
{
    if (c1 == c2)
        return true;
    if ((!c1 && c2) || (c1 && !c2))
        return false;
    return (*c1 == *c2);
}

bool StyleRareInheritedData::operator==(const StyleRareInheritedData& o) const
{
    return textStrokeColor == o.textStrokeColor
        && textStrokeWidth == o.textStrokeWidth
        && textFillColor == o.textFillColor
        && textEmphasisColor == o.textEmphasisColor
        && shadowDataEquivalent(o)
        && highlight == o.highlight
        && cursorDataEquivalent(cursorData.get(), o.cursorData.get())
        && indent == o.indent
        && m_effectiveZoom == o.m_effectiveZoom
        && widows == o.widows
        && orphans == o.orphans
        && textSecurity == o.textSecurity
        && userModify == o.userModify
        && wordBreak == o.wordBreak
        && wordWrap == o.wordWrap
        && nbspMode == o.nbspMode
        && khtmlLineBreak == o.khtmlLineBreak
        && textSizeAdjust == o.textSizeAdjust
#ifdef ANDROID_CSS_RING
        && ringFillColor == o.ringFillColor
        && ringInnerWidth == o.ringInnerWidth
        && ringOuterWidth == o.ringOuterWidth
        && ringOutset == o.ringOutset
        && ringPressedInnerColor == o.ringPressedInnerColor
        && ringPressedOuterColor == o.ringPressedOuterColor
        && ringRadius == o.ringRadius
        && ringSelectedInnerColor == o.ringSelectedInnerColor
        && ringSelectedOuterColor == o.ringSelectedOuterColor
#endif
#ifdef ANDROID_CSS_TAP_HIGHLIGHT_COLOR
        && tapHighlightColor == o.tapHighlightColor
#endif
        && resize == o.resize
        && userSelect == o.userSelect
        && colorSpace == o.colorSpace
        && speak == o.speak
        && hyphens == o.hyphens
        && textEmphasisFill == o.textEmphasisFill
        && textEmphasisMark == o.textEmphasisMark
        && textEmphasisPosition == o.textEmphasisPosition
        && hyphenationString == o.hyphenationString
        && hyphenationLocale == o.hyphenationLocale
        && textEmphasisCustomMark == o.textEmphasisCustomMark;
}

bool StyleRareInheritedData::shadowDataEquivalent(const StyleRareInheritedData& o) const
{
    if ((!textShadow && o.textShadow) || (textShadow && !o.textShadow))
        return false;
    if (textShadow && o.textShadow && (*textShadow != *o.textShadow))
        return false;
    return true;
}

} // namespace WebCore
