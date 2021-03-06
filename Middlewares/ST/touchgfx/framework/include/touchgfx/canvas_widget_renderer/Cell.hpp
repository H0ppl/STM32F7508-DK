/******************************************************************************
* Copyright (c) 2018(-2021) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.18.1 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

/**
 * @file touchgfx/canvas_widget_renderer/Cell.hpp
 *
 * Declares the touchgfx::Cell struct. Used internally by CanvasWidgetRenderer.
 */
#ifndef TOUCHGFX_CELL_HPP
#define TOUCHGFX_CELL_HPP

#include <touchgfx/hal/Types.hpp>

/// @cond
namespace touchgfx
{
/**
 * A pixel cell. There are no constructors defined and it was done intentionally in order to
 * avoid extra overhead when allocating an array of cells.
 */
struct Cell
{
    int16_t x;     ///< The x coordinate
    int16_t y;     ///< The y coordinate
    int16_t cover; ///< The cover (see http://projects.tuxee.net/cl-vectors/section-the-cl-aa-algorithm for further information).
    int16_t area;  ///< The area (see http://projects.tuxee.net/cl-vectors/section-the-cl-aa-algorithm for further information).

    /**
     * Sets all the Cell parameters.
     *
     * @param  _x     The x coordinate.
     * @param  _y     The y coordinate.
     * @param  _cover The cover.
     * @param  _area  The area.
     */
    void set(int _x, int _y, int _cover, int _area)
    {
        setCoord(_x, _y);
        setCover(_cover, _area);
    }

    /**
     * Sets the coordinate of the Cell.
     *
     * @param  _x The Cell's x coordinate.
     * @param  _y The Cell's y coordinate.
     */
    void setCoord(int _x, int _y)
    {
        x = int16_t(_x);
        y = int16_t(_y);
    }

    /**
     * Sets the cover of area cell.
     *
     * @param  _cover The cover.
     * @param  _area  The area.
     */
    void setCover(int _cover, int _area)
    {
        cover = _cover;
        area = _area;
    }

    /**
     * Adds a cover to a Cell.
     *
     * @param  _cover The cover to add to the Cell.
     * @param  _area  The area to add to the Cell.
     */
    void addCover(int _cover, int _area)
    {
        cover += _cover;
        area += _area;
    }

    /**
     * Packed coordinates of the Cell. By packing the x coordinate and y coordinate into one int,
     * it is possible to sort Cells using a single comparison.
     *
     * @return The packed coordinates with y in the high part and x in the low part.
     */
    FORCE_INLINE_FUNCTION int packedCoord() const
    {
        return packedCoord(x, y);
    }

    /**
     * Packed x,y coordinates. By packing the x coordinate and y coordinate into one int, it is
     * possible to sort Cells using a single comparison.
     *
     * @param  x The x coordinate.
     * @param  y The y coordinate.
     *
     * @return The packed coordinates with y in the high part and x in the low part.
     */
    FORCE_INLINE_FUNCTION static int packedCoord(int16_t x, int16_t y)
    {
        return (y << 16) + x;
    }
}; // struct Cell

} // namespace touchgfx
/// @endcond

#endif // TOUCHGFX_CELL_HPP
