// Hello : )


#include "Game/LobbyGameMode.h"
#include "GameFramework/GameState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	
	if(NumberOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		if(World)
		{
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Blueprints/Maps/TestingMap1?listen"));
		}
		
	}
}
