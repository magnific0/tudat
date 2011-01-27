/*! \file gravity.h
 *    Header file that defines the gravity force model included in Tudat.
 *
 *    Path              : /Astrodynamics/ForceModels/
 *    Version           : 6
 *    Check status      : Checked
 *
 *    Author            : K. Kumar
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : K.Kumar@tudelft.nl
 *
 *    Checker           : D. Dirkx
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : D.Dirkx@student.tudelft.nl
 *
 *    Date created      : 16 September, 2010
 *    Last modified     : 19 January, 2011
 *
 *    References
 *
 *    Notes
 *
 *    Copyright (c) 2010 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    author              comment
 *      100916    K. Kumar            File created.
 *      100916    K. Kumar            Filename modified.
 *      100929    D. Dirkx            File checked.
 *      100929    K. Kumar            Minor corrections to include statements
 *                                    and comments.
 *      110113    K. Kumar            Changed setBody() argument to pointer;
 *                                    added pointer to GravityFieldModel.
 *      110119    K. Kumar            Changed computeStateDerivatives() to
 *                                    computeForce().
 */

#ifndef GRAVITY_H
#define GRAVITY_H

// Include statements.
#include <cmath>
#include "forceModel.h"
#include "celestialBody.h"
#include "gravityFieldModel.h"

//! Gravity force class.
/*!
 * Class containing the gravity force model.
 */
class Gravity : public ForceModel
{
public:

    //! Default constructor.
    /*!
     * Default constructor.
     */
    Gravity( );

    //! Default destructor.
    /*!
     * Default destructor.
     */
    ~Gravity( );

    //! Set body for gravity field expansion.
    /*!
     * This function sets the body for gravity field expansion.
     * \param celestialBody Celestial body which is set.
     */
    void setBody( CelestialBody* celestialBody );

    //! Compute forces per unit mass for gravity field expansion.
    /*!
     * This function computes the forces per unit mass for gravity field
     * expansion.
     * \param stateVector State vector of size 6; first three cartesian
     * position coordinates, followed by three cartesian velocity coordinates.
     * \return Force per unit mass computed from gravity field and position.
     */
    VectorXd& computeForce( VectorXd& stateVector );

protected:

private:

    //! Pointer to gravity field model.
    /*!
     * Pointer to gravity field model.
     */
    GravityFieldModel* pointerToGravityFieldModel_;
};

#endif // GRAVITY_H

// End of file.