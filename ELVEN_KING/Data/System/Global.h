#pragma once
#include "Debug.h"
#include "Database.h"
#include "Audio.h"
#include "Control.h"
#include "Graphics.h"
#include "Stage.h"

Database database(DATABASE_NAME);
Control  control;
Audio	 audio;
Graphics graphics;
Stage	*stage = NULL;