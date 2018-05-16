/*
 * Swarm.h
 *
 *  Created on: May 16, 2018
 *      Author: moham
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace caveofprogramming {

class Swarm {
public:
	const static int NPARTICLES = 10000;

private:
	Particle *  m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();

	const Particle * const getParticles(){
		return m_pParticles;
	}

	void update(int elapsed);
};

} /* namespace caveofprogramming */

#endif /* SWARM_H_ */
