//PhysicsManager.h

#ifndef _PHYSICSMANAGER_
#define _PHYSICSMANAGER_
#include "spaceship.h"

enum BodyType{
	BT_PLANE,
	BT_SPHERE,
	BT_CYLINDER,
	BT_CAPSULE,
	BT_AABB
};

typedef struct
{
	BodyType type;
	int id;
	PhyStruct()
	{
		
	}
	virtual ~PhyStruct()
	{
		physicsManager->
	}
} PhyStruct;

typedef struct _Plane: PhyStruct
{
	TVector _Pos;
	TVector _Normal;
	_Plane()
	{
		type=BT_PLANE;
	}
} Plane;

typedef struct _Sphere: PhyStruct
{
	TVector _Pos;
	float _radius;
	_Sphere()
	{
		type=BT_SPHERE;
	}
} Sphere;

typedef struct _Cylinder: PhyStruct
{
	TVector _Pos;
	float _radius;
	float height;
	_Cylinder()
	{
		type=BT_CYLINDER;
	}
} Cylinder;

typedef struct _Capsule: PhyStruct
{
	TVector _Pos;
	float _radius;
	float _height;
	_Capsule()
	{
		type=BT_CAPSULE;
	}
} Capsule;

typedef struct _AxisAlignedBB: PhyStruct
{
	TVector _Pos;
	TVector _End;
	_AxisAlignedBB()
	{
		type=BT_AABB;
	}
} AxisAlignedBB;

typedef struct
{
	TVector _Pos;
	float dist;
} RayCastInfo;

typedef struct
{
	TVector _Pos;
	float _amt;
} CollisionInfo;

class SimIsland
{
	public:
		void Update(DWORD mills);
		bool RayCast(int ray, RayCastInfo &info);
		bool RayCast(int ray, RayCastInfo &info[],int &num);
		bool Collide(int a, int b, CollisionInfo &info);
		bool Collide(int a, int b, CollisionInfo &info[],int &num);
	private:
		RigidBody bodies[];
		int numOfBodies;
};

class PhysicsManager
{
	public:
		void Update(DWORD mills);
		bool RayCast(int ray, RayCastInfo &info);
		bool RayCast(int ray, RayCastInfo &info[],int &num);
		bool Collide(int a, int b, CollisionInfo &info);
		bool Collide(int a, int b, CollisionInfo &info[],int &num);
		
		int RegisterObject();
		PhyStruct * GetObjectPtr(int id);
		void UnRegisterObject(int id);
	private:
		SimIsland islands[];
		int numOfIslands;
		#define MAX_OBJECTS 1024
		PhyStruct * ObjectPtr[MAX_OBJECTS];
		int nextID;
};
#endif
