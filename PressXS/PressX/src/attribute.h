// name: attribute.h
// type: c++ header
// desc: enum
// auth: is0urce

// enum for statistics attributes

#pragma once

namespace px
{
	namespace rl
	{
		enum class attribute : int
		{
			undefined,

			strength,
			intelligence,
			dexterity,

			damage,
			armor,

			vitality,
			dodge_rating,
			resist_rating,

			critical_rating,
			accuracy_rating,
			mastery_rating,

			dodge_bonus,
			resist_bonus,

			critical_bonus,
			accuracy_bonus,
			mastery_bonus,
			
			min_attribute = undefined,
			max_attribute = mastery_bonus
		};

	}
}