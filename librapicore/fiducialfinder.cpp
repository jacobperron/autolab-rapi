/***************************************************************************
 * Project: RAPI                                                           *
 * Author:  Jens Wawerla (jwawerla@sfu.ca)                                 *
 * $Id: $
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 **************************************************************************/
#include "fiducialfinder.h"
#include "utilities.h"
#include "rapierror.h"
#include <stdio.h>

namespace Rapi
{

//-----------------------------------------------------------------------------
AFiducialFinder::AFiducialFinder ( std::string devName )
    : ADevice ( devName )
{
  mFov = 0.0;
  mMinRange = 0.0;
  mMaxRange = 0.0;
  mNumReadings = 0;
  mOwnFiducialId = 0;
  mFiducialData = NULL;
}
//-----------------------------------------------------------------------------
AFiducialFinder::~AFiducialFinder()
{
  if ( mFiducialData )
    delete[] mFiducialData;
}
//-----------------------------------------------------------------------------
double AFiducialFinder::getMinRange() const
{
  return mMinRange;
}
//-----------------------------------------------------------------------------
double AFiducialFinder::getMaxRange() const
{
  return mMaxRange;
}
//-----------------------------------------------------------------------------
double AFiducialFinder::getFov() const
{
  return mFov;
}
//-----------------------------------------------------------------------------
unsigned int AFiducialFinder::getNumReadings() const
{
  return mNumReadings;
}
//-----------------------------------------------------------------------------
void AFiducialFinder::print() const
{
  printf ( "AFiducialFinder: readings %d \n", mNumReadings );

  for ( unsigned int i = 0; i < mNumReadings; i++ ) {
    printf ( "  id %d range %f bearing %f\n", mFiducialData[i].id,
             mFiducialData[i].range,  R2D ( mFiducialData[i].bearing ) );
  }
}
//-----------------------------------------------------------------------------
int AFiducialFinder::getFiducialSignal() const
{
  return mOwnFiducialId; 
}
//-----------------------------------------------------------------------------
}  // namespace
