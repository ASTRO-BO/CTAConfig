//
//  HexagonalGridMap.cpp
//  Clean
//
//  Created by Alessio Aboudan on 02/10/14.
//  Copyright (c) 2014 IASF. All rights reserved.
//

#include <cstdio>
#include <limits>
#include <cmath>

#include <ctautils/Matrix.h>

#include "CTAGridMap.h"

using namespace std;

namespace CTAConfig {

CTAGridMap::CTAGridMap(Size n, Size *row, Size *col, Index *pixId) : pixId(0), xc(0), yc(0), xs(0), ys(0), nr(0), nc(0), r(0), c(0) {

	// Record the number of valid pixels
	this->n = n;
	
	// Parse row/col list searching max values
	for (Size i = 0; i < n; i++) {
		if (row[i] > r)
			r = row[i];
		if (col[i] > c)
			c = col[i];
	}
	
	// Number of rows/cols are max index + 1
	r++;
	c++;
	
	// Allocate pixelID
	this->pixId = matrixCreate<Index>(r, c);
	
	// Init
	for (Size i = 0; i < r; i++)
		for (Size j = 0; j < c; j++)
			this->pixId[i][j] = -1;

	// Copy data
	for (Size i = 0; i < n; i++)
		this->pixId[row[i]][col[i]] = pixId[i];
    
}

CTAGridMap::~CTAGridMap() {

    matrixDestroy<Index>(r, c, pixId);
    
    if (xc) {
		matrixDestroy<Coordinate>(r, c, xc);
		matrixDestroy<Coordinate>(r, c, yc);
	}
	
	if (xs) {
		matrixDestroy<Coordinate>(r, c, xs);
		matrixDestroy<Coordinate>(r, c, ys);
	}
	
	if (nr) {
		matrixDestroy<Index>(r, c, nr);
		matrixDestroy<Index>(r, c, nc);
	}
    
}

void CTAGridMap::fillLUT(LUTSelectionMask lutSel) {
	
    if (lutSel & GM_CENTRE_LUT) {
        
		xc = matrixCreate<Coordinate>(r, c);
		yc = matrixCreate<Coordinate>(r, c);
        
        fillCentreLUT();
        
    }
    
	if (lutSel & GM_CORNERS_LUT) {
        
		xs = matrixCreate<Coordinate>(r, c, getCornersSz());
		ys = matrixCreate<Coordinate>(r, c, getCornersSz());
        
        fillCornersLUT();
        
	}
	
	if (lutSel & GM_NEIGHBORS_LUT) {
		
		nr = matrixCreate<Index>(r, c, getNeighborsSz());
		nc = matrixCreate<Index>(r, c, getNeighborsSz());
		
		fillNeighborsLUT();
		
	}

}

bool CTAGridMap::getCellCentre(Size row, Size col, Coordinate *x, Coordinate *y) {
    
#ifdef GM_SAFE_CHECK
    
    if (isOutside(row, col))
        return false;
    
    if (xc == 0)
        return false;
    
#endif // GM_SAFE_CHECK
    
    *x = xc[row][col];
    *y = yc[row][col];
	
	return true;
    
}

bool CTAGridMap::getCellCorners(Size row, Size col, Coordinate *x, Coordinate *y) {
    
#ifdef GM_SAFE_CHECK
    
    if (isOutside(row, col))
        return false;
    
    if (xs == 0)
        return false;
    
#endif // GM_SAFE_CHECK
    
    memcpy(x, xs[row][col], getCornersSz()*sizeof(Coordinate));
    memcpy(y, ys[row][col], getCornersSz()*sizeof(Coordinate));
    
	return true;
	
}

bool CTAGridMap::getCellNeighbors(Size row, Size col, Index *nrow,  Index *ncol) {
	
#ifdef GM_SAFE_CHECK
	
	if (isOutside(row, col))
		return false;
	
	if (nr == 0)
		return false;
	
#endif // GM_SAFE_CHECK
	
	memcpy(nrow, nr[row][col], getNeighborsSz()*sizeof(Index));
	memcpy(ncol, nc[row][col], getNeighborsSz()*sizeof(Index));
	
	return true;
	
}

#ifdef GM_SAFE_CHECK
inline bool CTAGridMap::isOutside(Size row, Size col) {

    if (row >= r )
        return true;
    
    if (col >= c)
        return true;

    return false;
    
}
#endif // GM_SAFE_CHECK


const CTAGridMap::Index CTAHexagonalPointyTopOddRowGridMap::oddRowOff[6] = {-1, 0, 1, 1,  0, -1};
const CTAGridMap::Index CTAHexagonalPointyTopOddRowGridMap::oddColOff[6] = { 1, 1, 1, 0, -1,  0};

const CTAGridMap::Index CTAHexagonalPointyTopOddRowGridMap::evenRowOff[6] = {-1, 0, 1,  1,  0, -1};
const CTAGridMap::Index CTAHexagonalPointyTopOddRowGridMap::evenColOff[6] = { 0, 1, 0, -1, -1, -1};

CTAHexagonalPointyTopOddRowGridMap::CTAHexagonalPointyTopOddRowGridMap(Size n, Size *row, Size *col, Index *pixId, Coordinate side) : CTAGridMap(n, row, col, pixId), s(side) {
    
    // Precompute LUT parameteres
    h = 2*s;
    w = h*sqrt(3)/2;
    
}

void CTAHexagonalPointyTopOddRowGridMap::fillCentreLUT() {
    
    for (Size i = 0; i < r; i++) {
        
        Coordinate x0 = w/2;
        
        if (i & 1) // Odd column index
            x0 += w/2;
        
        Coordinate y0 = h/2 + i*3*h/4;
            
        for (Size j = 0; j < c; j++) {
            
            xc[i][j] = x0 + w*j;
            
            yc[i][j] = y0;
            
        }
    }
    
}

void CTAHexagonalPointyTopOddRowGridMap::fillCornersLUT() {
    
    if (xc == 0)
        return;
	
	Coordinate dx[6], dy[6];
	
	dx[0] = 0;
	dy[0] = -h/2;
	
	dx[1] = w/2;
	dy[1] = -h/4;
	
	dx[2] = w/2;
	dy[2] = h/4;
	
	dx[3] = 0;
	dy[3] = h/2;
	
	dx[4] = -w/2;
	dy[4] = h/4;
	
	dx[5] = -w/2;
	dy[5] = -h/4;
	
    for (Size i = 0; i < r; i++) {
        
        for (size_t j = 0; j < c; j++) {
            
            for (Size k = 0; k < 6; k++) {
            
                xs[i][j][k] = xc[i][j] + dx[k];
                ys[i][j][k] = yc[i][j] + dy[k];
                
            }
            
        }
        
    }
    
}

void CTAHexagonalPointyTopOddRowGridMap::fillNeighborsLUT() {
    
    for (Size i = 0; i < r; i++) {
        
        // Select offset lookup table
        const Index *colOff, *rowOff;
        if (i & 1) {            // Odd row
            colOff = oddColOff;
            rowOff = oddRowOff;
        } else {                // Even row
            colOff = evenColOff;
            rowOff = evenRowOff;
        }
        
        for (Size j = 0; j < c; j++) {
            
            for (Size k = 0; k < 6; k++) {
                
                if (i == 0 && rowOff[k] < 0) {
                    nr[i][j][k] = -1;
                    nc[i][j][k] = -1;
                    continue;
                }
                
                if (i == r-1 && rowOff[k] > 0) {
                    nr[i][j][k] = -1;
                    nc[i][j][k] = -1;
                    continue;
                }

                if (j == 0 && colOff[k] < 0) {
                    nr[i][j][k] = -1;
                    nc[i][j][k] = -1;
                    continue;
                }
                
                if (j == c-1 && colOff[k] > 0) {
                    nr[i][j][k] = -1;
                    nc[i][j][k] = -1;
                    continue;
                }
                
                
                // Update
                nr[i][j][k] = i + rowOff[k];
                nc[i][j][k] = j + colOff[k];
                
            }
        }
    }
}

}
