#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H
#include "MathHelper.h"

namespace EasySDL
{
	class GameEntity
	{
	public:
	
		enum SPACE {local = 0, world = 1};
	
		GameEntity(Vector2 pos = VEC2_ZERO);
		~GameEntity();
	
		void Position(Vector2 position);
		Vector2 Position(SPACE space = world);
	
		void Scale(Vector2 scale);
		Vector2 Scale(SPACE space = world);
	
		void Rotation(float rotation);
		float Rotation(SPACE space = world);
	
		void Active(bool active);
		bool Active();
	
		void Parent(GameEntity* parent);
		GameEntity* Parent();
	
		void Translate(Vector2 vec);
		void Rotate(float amount);
	
		virtual void Update();
		virtual void Render();
	
	private:
	
		Vector2 mPos;
		Vector2 mScale;
		float mRotation;
	
		bool mActive;
		GameEntity* mParent;
	
	
	};
}


#endif // _GAMEENTITY_H
