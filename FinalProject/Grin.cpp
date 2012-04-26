#pragma once

#include "DarkGDK.h"
#include <string>
#include <map>
using namespace std;
#include "Grin.h"


Grin::Grin(void)
{
	grinState["STANDING"] = 2;
	grinState["RUNNING"]  = 3;
	grinState["SHOOTING"] = 4;
	xPos = 20;
	yPos = 400;
	spriteState = 1;
	dbLoadImage("standing.bmp", grinState["STANDING"]);
	dbLoadImage("running.bmp", grinState["RUNNING"]);
	dbLoadImage("shooting.bmp", grinState["SHOOTING"]);
	dbSetSpriteImage(grinState["STANDING"], grinState["STANDING"]);
	dbSetSpriteImage(grinState["RUNNING"], grinState["RUNNING"]);
	dbSetSpriteImage(grinState["SHOOTING"], grinState["SHOOTING"]);
	dbCreateAnimatedSprite(grinState["RUNNING"], "running.bmp", 3, 1, grinState["RUNNING"]);
}
Grin::~Grin(void)
{
}
void Grin::move()
{
	if ( dbRightKey() || dbLeftKey() )
	{
		leftOrRight();
	}
	if ( dbRightKey() )
	{
		moveRight();
	}
	if ( dbLeftKey() )
	{
		moveLeft();
	}
	if ( dbSpaceKey() )
	{
		shoot();
	}
	if ( !dbLeftKey() && !dbRightKey() && !dbSpaceKey() )
	{
		stand();
	}
}
void Grin::shoot()
{
	showHide("SHOOTING");
	spriteState = grinState["SHOOTING"];
	if ( dbSpriteMirrored(grinState["RUNNING"]) != 0)
		dbMirrorSprite(grinState["SHOOTING"]);
}
void Grin::leftOrRight()
{
	showHide("RUNNING");
	spriteState = grinState["RUNNING"];
	dbPlaySprite(grinState["RUNNING"], 1, 3, 100);
}
void Grin::moveRight()
{		
	xPos += 3;
	if ( dbSpriteMirrored(grinState["RUNNING"]) != 0)
		dbMirrorSprite(grinState["RUNNING"]);
}
void Grin::moveLeft()
{
	xPos -= 3;
	if ( dbSpriteMirrored(grinState["RUNNING"]) == 0)
		dbMirrorSprite(grinState["RUNNING"]);
}
void Grin::stand()
{
	showHide("STANDING");

	spriteState = grinState["STANDING"];

	if ( dbSpriteMirrored(grinState["STANDING"]) == 0 && dbSpriteMirrored(grinState["RUNNING"]) != 0)
	{
		dbMirrorSprite(grinState["STANDING"]);
	}
	else if ( dbSpriteMirrored(grinState["STANDING"]) != 0 && dbSpriteMirrored(grinState["RUNNING"]) == 0)
	{
		dbMirrorSprite(grinState["STANDING"]);
	}
}
void Grin::draw()
{
	dbSprite(spriteState, xPos, yPos, spriteState);
}
void Grin::showHide(string show)
{
	for each( const pair<string, int> &grnState in grinState )
		if ( dbSpriteVisible(grnState.second) )
			dbHideSprite(grnState.second);

	if ( !dbSpriteVisible(grinState[show]) )
		dbShowSprite(grinState[show]);
}