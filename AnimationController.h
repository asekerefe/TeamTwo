/*
	Copyright (C) 2011-2012  Alican Sekerefe 

	TeamTwo is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TeamTwo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Contact: projectteamtwo@gmail.com
*/

#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H
#include "stdafx.h"

//a struct that is used by the AnimationController
//in order to hold details about the animation 
typedef struct AnimationInfo
{
    AnimationState* state;
    AnimationState* idleState;
    bool enabled;
    double speed;
    bool loop;
    bool playTillEnd;
    bool oneFrame;
    bool autoDisable;
}AnimationInfo_t;

/* Animation Controller
 *
 * This class is responsible for providing a high
 * level animation interface using Ogre3D's own
 * animation handlers. Updating an animation till
 * the last frame and reseting the animation to
 * the starting time are the main features of this
 * class.
 */

class AnimationController
{
    Entity* entity;
    std::map<std::string,AnimationInfo_t*> animationMap;
    //initializes the animations of given Ogre::Entity object
    void initialize();

public:
    //takes the given entity and initializes the controller
    AnimationController(Entity* entity);
    //updates the animation only one frame by considering its speed.
    //loop is defined as "true" by default so that if the animation reaches
    //to the end, it starts over.
    void updateOneFrame(std::string animationName,double speed,bool loop=true);
    //enables the given animation on the entity object
    void enableAnimation(std::string animationName);
    //disables the given animation on the entity object
    void disableAnimation(std::string animationName);
    //updates all of the specified animations per one frame
    //this method must be called at the each frame of the game
    void updateAnimations(double updateTime);
    //returns the current time position of the animation
    double getAnimationTime(std::string animationName);
    //returns the max. time position of the animation
    double getAnimationLength(std::string animationName);
    //plays the animation to the end of the animation length.
    //this should be used for continious animations like
    //"death" or "jump".
    void playTillEnd(std::string animationName,double speed,bool autoDisable=false);
    //returns the animation state
    AnimationState* getAnimationState(std::string animationName);
	//adds an idle animation which going to be used when there are no other
	//active animations running
    void addIdleAnimation(std::string sourceAnimation,std::string subAnimation);
};



#endif