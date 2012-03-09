﻿// * This file is part of the COLOBOT source code
// * Copyright (C) 2001-2008, Daniel ROUX & EPSITEC SA, www.epsitec.ch
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see .

#define STRICT
#define D3D_OVERLOADS

#include <windows.h>
#include <stdio.h>
#include <d3d.h>

#include "struct.h"
#include "D3DEngine.h"
#include "math3d.h"
#include "event.h"
#include "misc.h"
#include "iman.h"
#include "text.h"
#include "label.h"




// Constructeur de l'objet.

CLabel::CLabel(CInstanceManager* iMan) : CControl(iMan)
{
	CControl::CControl(iMan);
}

// Destructeur de l'objet.

CLabel::~CLabel()
{
	CControl::~CControl();
}


// Cr�e un nouveau bouton.

BOOL CLabel::Create(FPOINT pos, FPOINT dim, int icon, EventMsg eventMsg)
{
	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	CControl::Create(pos, dim, icon, eventMsg);
	return TRUE;
}


// Gestion d'un �v�nement.

BOOL CLabel::EventProcess(const Event &event)
{
//?	CControl::EventProcess(event);
	return TRUE;
}


// Dessine le bouton.

void CLabel::Draw()
{
	FPOINT	pos;

	if ( (m_state & STATE_VISIBLE) == 0 )  return;

	pos.y = m_pos.y+m_dim.y/2.0f;

	if ( m_justif > 0 )
	{
		pos.x = m_pos.x;
	}
	if ( m_justif == 0 )
	{
		pos.x = m_pos.x+m_dim.x/2.0f;
	}
	if ( m_justif < 0 )
	{
		pos.x = m_pos.x+m_dim.x;
	}
	m_engine->RetText()->DrawText(m_name, pos, m_dim.x, m_justif, m_fontSize, m_fontStretch, m_fontType, 0);
}

