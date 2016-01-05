#pragma once
#include "Debug.h"
#include "Database.h"
#include "Graphics.h"
#include "Audio.h"
#include "Control.h"
#include "Stage.h"

Database database(DATABASE_NAME);
Graphics graphics;
Control  control;
Audio	 audio;
Stage	*stage = NULL;