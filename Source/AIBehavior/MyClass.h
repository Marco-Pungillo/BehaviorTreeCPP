// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"

/**
 * 
 */
class AIBEHAVIOR_API MyClass
{
public:
	MyClass();
	~MyClass();

	template<class T>
	bool GetObject(T* InObject)
	{
		static_assert(std::is_base_of<AActor, T>::value, "Must inherit form AActor");
		
		//do things

		return true;
	}
};
