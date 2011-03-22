////////////////////////////////////////////////////////////////////////////////////
///
///  \file vehicle.h
///  \brief This file contains the Vehicle class used to store information about
///         subsystems (e.g. a Vehicle/Vehicle) that has been discovered.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 15 November 2009
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu
///  <br>Web:  http://active.ist.ucf.edu
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///      * Redistributions of source code must retain the above copyright
///        notice, this list of conditions and the following disclaimer.
///      * Redistributions in binary form must reproduce the above copyright
///        notice, this list of conditions and the following disclaimer in the
///        documentation and/or other materials provided with the distribution.
///      * Neither the name of the ACTIVE LAB, IST, UCF, nor the
///        names of its contributors may be used to endorse or promote products
///        derived from this software without specific prior written permission.
/// 
///  THIS SOFTWARE IS PROVIDED BY THE ACTIVE LAB''AS IS'' AND ANY
///  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL UCF BE LIABLE FOR ANY
///  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
///  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
///  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
///  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
///  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
////////////////////////////////////////////////////////////////////////////////////
#ifndef __JAUS_CORE_DISCOVERY_VEHICLE__H
#define __JAUS_CORE_DISCOVERY_VEHICLE__H

#include "jaus/core/service.h"
#include "jaus/core/discovery/subsystem.h"
#include <cxutils/math/coordinates.h>

namespace JAUS
{
    typedef CxUtils::Wgs Wgs;            ///<  Typedef to more easily reference Wgs data.
    typedef CxUtils::Point3D Attitude;   ///<  Typedef to more easily reference Point3D data as orientation.

    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class Vehicle
    ///   \brief Describes a Vehicle Subsystem.  A Vehicle has position and 
    ///          orientation information.
    ///
    ///   Within the Core library, vehicle positions and orientations are not
    ///   set.  They are only updated when the Discovery Service is used in
    ///   conjunction with the Mobility Service Set library.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_CORE_DLL Vehicle : public Subsystem
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////////
        ///
        ///   \class Info
        ///   \brief Abstract class for setting additional information you want to
        ///          assign to a vehicle.  
        ///
        ///   Overload this classes methods, and then you can call the SetAdditionalInfo
        ///   methods of the Vehicle class to set custom virtual data.
        ///
        ////////////////////////////////////////////////////////////////////////////////////
        class JAUS_CORE_DLL Info
        {
        public:
            Info() {}
            virtual ~Info() {}
            virtual bool Copy(const Info* toCopy) = 0;
            virtual Info* Clone() const = 0;
        };
        typedef Mutex::ScopedPtr<Vehicle> Ptr;
        typedef std::map<UShort, Vehicle *> Map;
        Vehicle() { mAuthority = 0; mpInfo = NULL; }
        Vehicle(const Vehicle& vehicle) : Subsystem() { mpInfo = NULL; *this = vehicle; }
        ~Vehicle() { if(mpInfo) { delete mpInfo; } }
        void Update(const Wgs& position,
                    const Attitude& attitude,
                    const Time& time)
        {
            mPosition = position;
            mAttitude = attitude;
            mUpdateTime = time;
        }
        virtual Subsystem* Clone() const { return new Vehicle(*this); }
        void SetAdditionalInfo(const Info* info)
        {
            if(mpInfo == NULL)
            {
                mpInfo = info->Clone();
            }
            else
            {
                mpInfo->Copy(info);
            }
        }
        void DeleteAdditionalInfo()
        {
            if(mpInfo)
            {
                delete mpInfo;
            }
            mpInfo = NULL;
        }
        Info* GetAdditionalInfo() { return mpInfo; }
        const Info* GetAdditionalInfo() const { return mpInfo; }
        Vehicle& operator=(const Vehicle& vehicle)
        {
            if(this != &vehicle)
            {
                *((Subsystem *)this) = *((Subsystem *)&vehicle);
                mPosition = vehicle.mPosition;
                mAttitude = vehicle.mAttitude;
                mAuthority = vehicle.mAuthority;
                if(vehicle.mpInfo)
                {
                    if(mpInfo && mpInfo->Copy(vehicle.mpInfo) == false)
                    {
                        DeleteAdditionalInfo();
                        SetAdditionalInfo(vehicle.mpInfo);
                    }
                    else
                    {
                        SetAdditionalInfo(vehicle.mpInfo);
                    }
                }
                else if(mpInfo && !vehicle.mpInfo)
                {
                    DeleteAdditionalInfo();
                }
            }
            return *this;
        }
        static void DeleteVehicleMap(Map& list)
        {
            Map::iterator s;
            for(s = list.begin();
                s != list.end();
                s++)
            {
                delete s->second;
            }
            list.clear();
        }
        static void CopyVehicleMap(const Map& src, Map& dest)
        {
            Map::const_iterator s;
            DeleteVehicleMap(dest);
            for(s = src.begin();
                s != src.end();
                s++)
            {
                dest[s->first] = (Vehicle *)s->second->Clone();
            }
        }
        Wgs mPosition;          ///<  Position of Vehicle.
        Attitude mAttitude;     ///<  Attitude of Vehicle.
        Byte mAuthority;        ///<  Authority level needed for control of the Vehicle.
    private:
        Info* mpInfo;           ///<  Additional info for the vehicle.
    };
}

#endif
/*  End of File */
