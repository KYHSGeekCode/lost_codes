//PhysicsManager.cpp

#include "spaceship.h"
#include "physicsmanager.h"


////How To RegisterObject:
////
////
////
////
//int PhysicsManager::RegisterObject(PhyStruct * ptr)
//{
//	if(!ptr)
//	{
//		return -1;
//	}
//	if(nextID>=MAX_OBJECTS)
//	{
//		for(nextID=0;nextID<MAX_OBJECTS;nextID++)
//		{
//			if(ObjectsPtr[nextID]==NULL)
//			{
//				ObjectsPtr[nextID]=ptr;
//				int t=nextID;
//				nextID=MAX_OBJECTS;
//				return t;
//			}
//		}
//		return -1;
//	}
//	ObjectsPtr[nextID]=ptr;
//	return nextID++;
//}
//
//void PhysicsManager::UnRegisterObject(int id)
//{
//	if(id>=MAX_OBJECTS||id<0)
//	{
//		return;
//	}
//	ObjectsPtr[id]=NULL;
//}
//
//PhyStruct *PhysicsManager::GetObjectPtr(int id)
//{
//	if(id>=MAX_OBJECTS||id<0)
//	{
//		return NULL;
//	}
//	return ObjectsPtr[id];
//}
//
//dWorldID world=0;
//dSpaceID space=0;
//dThreadingImplementationID threading=0;
//dThreadingThreadPoolID 	pool=0;
//dBodyID 	body[100]={0,};
//int 	bodies=0;
//dJointID 	joint[100]={0,};
//int 	joints=0;
//dJointGroupID contactgroup=0;
//dGeomID ground=0;
//int wb_stepsdis[100]={0,};
//int wb=0;
//bool doFast=0;
//dBodyID b=0;
////dMass m=;

bool PhysicsManager::Initialize()
{
	dInitODE2(0);
	dAllocateODEDataForThread(dAllocateMaskAll);
	world=dWorldCreate();
	space=dSimpleSpaceCreate(0);
	contactgroup = dJointGroupCreate (0);
	dWorldSetGravity (world,0,0,-1.5);
	dWorldSetCFM (world, 1e-5);
	dWorldSetERP (world, 0.8);
	dWorldSetQuickStepNumIterations (world,5);

	threading = dThreadingAllocateMultiThreadedImplementation();
	pool = dThreadingAllocateThreadPool(4, 0, dAllocateFlagBasicData, NULL);
	dThreadingThreadPoolServeMultiThreadedImplementation(pool, threading);
	// dWorldSetStepIslandsProcessingMaxThreadCount(world, 1);
	dWorldSetStepThreadingImplementation(world, dThreadingImplementationGetFunctions(threading), threading);
}
bool PhysicsManager::Finalize()
{
	if(space)
	{
		dSpaceDestroy(space);
	}
	if(world)
	{
		dWorldDestroy(world);
	}
	dThreadingImplementationShutdownProcessing(threading);
	dThreadingFreeThreadPool(pool);
	dWorldSetStepThreadingImplementation(world, NULL, NULL);
	dThreadingFreeImplementation(threading);
	dJointGroupDestroy (contactgroup);
	dCloseODE();
}
void nearCallback (void *data, dGeomID o1, dGeomID o2)
{
	int i,n;

	dBodyID b1 = dGeomGetBody(o1);
	dBodyID b2 = dGeomGetBody(o2);
	if (b1 && b2 && dAreConnected(b1, b2))
		return;

	const int N = 4;
	dContact contact[N];
	n = dCollide (o1,o2,N,&contact[0].geom,sizeof(dContact));
	if (n > 0)
	{
		for (i=0; i<n; i++)
		{
			contact[i].surface.mode = dContactSlip1 | dContactSlip2 | dContactSoftERP | dContactSoftCFM | dContactApprox1;
			if (dGeomGetClass(o1) == dSphereClass || dGeomGetClass(o2) == dSphereClass)
				contact[i].surface.mu = 20;
			else
				contact[i].surface.mu = 0.5;
			contact[i].surface.slip1 = 0.0;
			contact[i].surface.slip2 = 0.0;
			contact[i].surface.soft_erp = 0.8;
			contact[i].surface.soft_cfm = 0.01;
			dJointID c = dJointCreateContact (physicsManager.world,physicsManager.contactgroup,contact+i);
			dJointAttach (c,dGeomGetBody(o1),dGeomGetBody(o2));
		}
	}
}

void PhysicsManager::Update (DWORD milliseconds)
{
	int i, j;

	//if (doFast)
	//{
	//	dSpaceCollide (space,0,&nearCallback);
	//	dWorldQuickStep (world,0.05);
	//	dJointGroupEmpty (contactgroup);
	//}
	//else
	{
		dSpaceCollide (space,0,nearCallback);
		dWorldStep (world,0.05);
		dJointGroupEmpty (contactgroup);
	}
}


