/*
 * Particle.h
 *
 *  Created on: May 16, 2018
 *      Author: N/A
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace caveofprogramming {

struct Particle { // by default in a class members are private. For a struct, by default members are public

	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();
public:
	Particle();
	virtual ~Particle();
	void update(int interval);

};

} /* namespace caveofprogramming */

#endif /* PARTICLE_H_ */
