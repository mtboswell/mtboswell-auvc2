////////////////////////////////////////////////////////////////////////////////////
///
///  \file reportglobalwaypoint.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Bo Sun
///  <br>Created: 25 November 2009
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: bsun@ist.ucf.edu
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
#ifndef __JAUS_MOBILITY_REPORT_GLOBAL_WAYPOINT__H
#define __JAUS_MOBILITY_REPORT_GLOBAL_WAYPOINT__H

#include "jaus/core/message.h"
#include "jaus/mobility/mobilitycodes.h"
#include <cxutils/math/cxmath.h>

namespace JAUS
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class ReportGlobalWaypoint
    ///   \brief This message is used to provide the receiver the values of the current
    ///          waypoint fields as specified by the data in the ID 240Ch:
    ///          QueryGlobalWaypoint.  The message data and mapping of the presence
    ///          vector of this message are identical to ID 040Ch: SetGlobalWaypoint.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_MOBILITY_DLL ReportGlobalWaypoint : public Message
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////////
        ///
        ///   \class PresenceVector
        ///   \brief This class contains bit masks for bitwise operations on the
        ///          presence vector for this message.
        ///
        ////////////////////////////////////////////////////////////////////////////////////
        class JAUS_MOBILITY_DLL PresenceVector : public JAUS::PresenceVector
        {
        public:
            const static Byte Altitude = 0x01;
            const static Byte Roll = 0x02;
            const static Byte Pitch = 0x04;
            const static Byte Yaw = 0x08;
            const static Byte WaypointTolerance = 0x10;
            const static Byte PathTolerance = 0x20;
        };
        ////////////////////////////////////////////////////////////////////////////////////
        ///
        ///   \class Limits
        ///   \brief Contains constants for limit values of data members of class.
        ///
        ////////////////////////////////////////////////////////////////////////////////////
        class JAUS_MOBILITY_DLL Limits : public JAUS::Limits
        {
        public:
            const static double MinLatitude;            ///<  Minimum latitude. (-90)
            const static double MaxLatitude;            ///<  Maximum latitude. (90)
            const static double MinLongitude;           ///<  Minimum longitude. (-180)
            const static double MaxLongitude;           ///<  Maximum longitude. (180)
            const static double MinElevation;           ///<  Minimum altitude. (-10000)
            const static double MaxElevation;           ///<  Maximum altitude. (35000)
            const static double MinAngle;               ///<  Minimum angle value in radians. (-PI)
            const static double MaxAngle;               ///<  Maximum angle value in radians. (PI)
            const static double MinWaypointTolerance;   ///< Minimum waypoint tolerance in meters. (0)
            const static double MaxWaypointTolerance;   ///< Maximum waypoint tolerance in meters. (100)
            const static double MinPathTolerance;       ///< Minimum path tolerance in meters. (0)
            const static double MaxPathTolerance;       ///< Maximum path tolerance in meters. (100000)
        };
        ReportGlobalWaypoint(const Address& dest = Address(), const Address& src = Address());
        ReportGlobalWaypoint(const ReportGlobalWaypoint& message);
        ~ReportGlobalWaypoint();
        bool SetLatitude(const double degrees);
        bool SetLongitude(const double degrees);
        bool SetAltitude(const double value);
        bool SetRoll(const double radians);
        bool SetPitch(const double radians);
        bool SetYaw(const double radians);
        bool SetWaypointTolerance(const double value);
        bool SetPathTolerance(const double value);
        inline double GetLatitude() const { return mLatitude; }
        inline double GetLongitude() const { return mLongitude; }
        inline double GetAltitude() const { return mAltitude; }
        inline double GetRoll() const { return mRoll; }
        inline double GetPitch() const { return mPitch; }
        inline double GetYaw() const { return mYaw; }
        inline double GetWaypointTolerance() const { return mWaypointTolerance; }
        inline double GetPathTolerance() const { return mPathTolerance; }
        Point3D GetPosition() const;
        Point3D GetOrientation() const;
        virtual bool IsCommand() const { return false; }
        virtual int WriteMessageBody(Packet& packet) const;
        virtual int ReadMessageBody(const Packet& packet);
        virtual Message* Clone() const { return new ReportGlobalWaypoint(*this); }
        virtual UInt GetPresenceVector() const { return mPresenceVector; }
        virtual UInt GetPresenceVectorSize() const { return BYTE_SIZE; }
        virtual UInt GetPresenceVectorMask() const { return 0x3F; }
        virtual UShort GetMessageCodeOfResponse() const { return 0; }
        virtual std::string GetMessageName() const { return "Report Global Waypoint"; }        
        virtual void ClearMessageBody();
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize = 1437) const { return false; }
        virtual int RunTestCase() const;
        ReportGlobalWaypoint& operator=(const ReportGlobalWaypoint& message);
    protected:
        Byte mPresenceVector;                   ///<  Bit vector for fields present.
        double mLatitude;                       ///<  Latitude in degrees [-90, 90].
        double mLongitude;                      ///<  Longitude in degrees [-180, 180].
        double mAltitude;                       ///<  Altitude in meters [-10000, 35000].
        double mRoll;                           ///<  Roll in radians [-PI, PI].
        double mPitch;                          ///<  Pitch in radians [-PI, PI].
        double mYaw;                            ///<  Yaw in radians [-PI, PI].
        double mWaypointTolerance;              ///<  Waypoint tolerance in meters [0, 100].
        double mPathTolerance;                  ///<  Path tolerance in meters [0, 100000], 0 used for infinite tolerance.

    };
}

#endif
/*  End of File */
