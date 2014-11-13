//
//  CTAGridMap.h
//  Clean
//
//  Created by Alessio Aboudan on 02/10/14.
//  Copyright (c) 2014 IASF. All rights reserved.
//

#ifndef __CTA_GRID_MAP_H__
#define __CTA_GRID_MAP_H__

#include <cstdlib>
#include <cstddef>
#include <cstdint>

#define GM_SAFE_CHECK

class CTAGridMap {

public:
	
	typedef uint16_t Size;
	typedef int16_t Index;
	typedef float Coordinate;
	
	enum LUTSelectionMask {
		GM_CENTRE_LUT    = 0x01,
		GM_CORNERS_LUT   = 0x02,
		GM_NEIGHBORS_LUT = 0x04,
		GM_LUT_DEFAULT   = GM_CENTRE_LUT + GM_NEIGHBORS_LUT,
		GM_LUT_ALL       = GM_LUT_DEFAULT + GM_CORNERS_LUT
	};
    
    enum CellType {
        GM_RECTANGULAR_4CONN = 0x00,
        GM_RECTANGULAR_8CONN,
        GM_HEXAGONAL_FLAT_TOP_ODD_COL,
        GM_HEXAGONAL_FLAT_TOP_EVEN_COL,
        GM_HEXAGONAL_POINTY_TOP_ODD_ROW,
        GM_HEXAGONAL_POINTY_TOP_EVEN_ROW,
    };
	
	Index **pixId;
	
	Coordinate **xc;
	Coordinate **yc;
	
	Coordinate ***xs;
	Coordinate ***ys;
	
	Index ***nr;
	Index ***nc;
    
    CTAGridMap(Size n, Size *row, Size *col, Index *pixId);
	virtual ~CTAGridMap();
    
    Size getRowSz() { return r; };
    Size getColSz() { return c; };
    
    virtual CellType getCellType() = 0;
    virtual Size getCornersSz()	= 0;
    virtual Size getNeighborsSz() = 0;
    
    void fillLUT(LUTSelectionMask lutSel =  GM_LUT_DEFAULT);
    
    bool getCellCentre(Size row, Size col, Coordinate *x, Coordinate *y);
    bool getCellCorners(Size row, Size col, Coordinate *x, Coordinate *y);
    bool getCellNeighbors(Size row, Size col, Index *nrow,  Index *ncol);
	
protected:
    
    Size r, c, n;
	
    virtual void fillCentreLUT() = 0;
	virtual void fillCornersLUT() = 0;
	virtual void fillNeighborsLUT() = 0;
	
#ifdef GM_SAFE_CHECK
    bool isOutside(Size row, Size col);
#endif // GM_SAFE_CHECK
    
private:
    
};

class CTAHexagonalPointyTopOddRowGridMap : public CTAGridMap {
	
public:
	
	CTAHexagonalPointyTopOddRowGridMap(Size n, Size *row, Size *col, Index *pixId, Coordinate side);
	
	Coordinate getCellSide() { return s; };
	Coordinate getCellWidth() { return w; };
	Coordinate getCellHeight() { return h; };
	
	CellType getCellType() { return GM_HEXAGONAL_FLAT_TOP_EVEN_COL; };
	Size getCornersSz() { return 6; };
	Size getNeighborsSz() { return 6; };
	
protected:
	
	static const Index oddRowOff[6];
	static const Index oddColOff[6];
	
	static const Index evenRowOff[6];
	static const Index evenColOff[6];
	
	void fillCentreLUT();
	void fillCornersLUT();
	void fillNeighborsLUT();
	
	Coordinate s, w, h;
	
private:
	
};

#endif // __RTA_GRID_MAP_H__
