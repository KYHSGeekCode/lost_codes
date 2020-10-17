#if 0
class UpdatedObject {
		virtual void Update(DWORD mills)=0;
		virtual bool NeedsUpdate() {
			return true;
		}
};
class TimeoutObject:public UpdatedObject {
		unsigned long left;
		virtual void Update(DWORD mills) {
			left-=mills;
			if(left<=0)OnTimeOut();
		}
		virtual bool NeedsUpdate() {
			return left>0;
		}
		virtual void OnTimeOut() {}
};

class PhysicsManager {
		bool Initialize() {
			dInitODE2(0);
			world=dWorldCreate();
			space=dSimpleSpaceCreate();
		}
#endif
