/*
 * Copyright 2011, Blender Foundation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor: 
 *		Jeroen Bakker 
 *		Monique Dewanchand
 */

#include "COM_ZCombineOperation.h"
#include "BLI_utildefines.h"

ZCombineOperation::ZCombineOperation() : NodeOperation()
{
	this->addInputSocket(COM_DT_COLOR);
	this->addInputSocket(COM_DT_VALUE);
	this->addInputSocket(COM_DT_COLOR);
	this->addInputSocket(COM_DT_VALUE);
	this->addOutputSocket(COM_DT_COLOR);

	this->m_image1Reader = NULL;
	this->m_depth1Reader = NULL;
	this->m_image2Reader = NULL;
	this->m_depth2Reader = NULL;

}

void ZCombineOperation::initExecution()
{
	this->m_image1Reader = this->getInputSocketReader(0);
	this->m_depth1Reader = this->getInputSocketReader(1);
	this->m_image2Reader = this->getInputSocketReader(2);
	this->m_depth2Reader = this->getInputSocketReader(3);
}

void ZCombineOperation::executePixel(float output[4], float x, float y, PixelSampler sampler)
{
	float depth1[4];
	float depth2[4];

	this->m_depth1Reader->read(depth1, x, y, sampler);
	this->m_depth2Reader->read(depth2, x, y, sampler);
	if (depth1[0] < depth2[0]) {
		this->m_image1Reader->read(output, x, y, sampler);
	}
	else {
		this->m_image2Reader->read(output, x, y, sampler);
	}
}
void ZCombineAlphaOperation::executePixel(float output[4], float x, float y, PixelSampler sampler)
{
	float depth1[4];
	float depth2[4];
	float color1[4];
	float color2[4];

	this->m_depth1Reader->read(depth1, x, y, sampler);
	this->m_depth2Reader->read(depth2, x, y, sampler);
	if (depth1[0] <= depth2[0]) {
		this->m_image1Reader->read(color1, x, y, sampler);
		this->m_image2Reader->read(color2, x, y, sampler);
	}
	else {
		this->m_image1Reader->read(color2, x, y, sampler);
		this->m_image2Reader->read(color1, x, y, sampler);
	}
	float fac = color1[3];
	float ifac = 1.0f - fac;
	output[0] = fac * color1[0] + ifac * color2[0];
	output[1] = fac * color1[1] + ifac * color2[1];
	output[2] = fac * color1[2] + ifac * color2[2];
	output[3] = max(color1[3], color2[3]);
}

void ZCombineOperation::deinitExecution()
{
	this->m_image1Reader = NULL;
	this->m_depth1Reader = NULL;
	this->m_image2Reader = NULL;
	this->m_depth2Reader = NULL;
}
