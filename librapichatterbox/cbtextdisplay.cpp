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
#include "cbtextdisplay.h"
#include "rapierror.h"

namespace Rapi
{


//-----------------------------------------------------------------------------
CCBTextDisplay::CCBTextDisplay ( CCBDriver* driver, std::string devName )
    : ATextDisplay ( devName )
{
  mCBDriver = driver;
  setEnabled( true );
}
//-----------------------------------------------------------------------------
CCBTextDisplay::~CCBTextDisplay()
{
  // turn off display
  mCBDriver->set7SegDisplay ( 0 );
}
//-----------------------------------------------------------------------------
int CCBTextDisplay::init()
{
  return true;
}
//-----------------------------------------------------------------------------
void CCBTextDisplay::setEnabled ( bool enable )
{
  if ( enable == true ) {
    mFgEnabled = true;
  } else {
    mFgEnabled = false;
    mCBDriver->set7SegDisplay ( 0 );
  }
}
//-----------------------------------------------------------------------------
int CCBTextDisplay::setText ( std::string text )
{
  if ( mFgEnabled ) {
    mText = text;
    if ( mText.empty() ) {
      return mCBDriver->set7SegDisplay ( 0 );
    }

    return mCBDriver->set7SegHexNumber ( text[0], CB_DONT_CARE );
  }
  return 1; // success
}
//-----------------------------------------------------------------------------
void CCBTextDisplay::updateData( const double dt)
{
}
//-----------------------------------------------------------------------------
int CCBTextDisplay::getSize() const
{
  return 1;  // we only have one 7 seg element
}
//-----------------------------------------------------------------------------

} // namespace
