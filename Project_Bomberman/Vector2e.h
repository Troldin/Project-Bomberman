#pragma once
/* Dwu elementowy wektor zawieraj¹cy dane o lokalizacji. */
namespace LocalizationVector {
	
	class Vector2e
	{
	public:

		float x, y;
	
		Vector2e() : x(0), y(0) {}
		Vector2e(float xValue, float yValue) : x(xValue), y(yValue) {}
		~Vector2e() = default;

		inline bool Equals(const Vector2e& delta) const
		{
			bool temp = false;
			if (x - delta.x ==0 && y - delta.y ==0)
			{
				temp = true;
			}
			return (temp);
		}


		inline Vector2e operator =(const Vector2e& delta)
		{
			return Vector2e(x = delta.x, y = delta.y);
		}
		
		inline Vector2e operator +(const Vector2e& delta) const
		{
			return Vector2e(x + delta.x, y + delta.y);
		};
		inline bool operator ==(const Vector2e& delta) const
		{
			return Equals(delta);
		};
	};
	
	

}
