// Fill out your copyright notice in the Description page of Project Settings.


#include "Exercise1/CentralActor.h"



void ACentralActor::CheckContextOfActors(TArray<APositionContextActor*> contextActors)
{

	for (int i = 0; i < contextActors.Num(); i++)
	{
		if (!contextActors[i])
			continue;

		auto context = UContextLibrary::GetAllPositionContext(this, contextActors[i]);
		contextActors[i]->SetContext(context);
	}
}
