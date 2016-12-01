#pragma once

#include "ZipUtilityInterface.h"
#include "ZipFileFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum ZipUtilityCompressionFormat
{
	COMPRESSION_FORMAT_UNKNOWN,
	COMPRESSION_FORMAT_SEVEN_ZIP,
	COMPRESSION_FORMAT_ZIP,
	COMPRESSION_FORMAT_GZIP,
	COMPRESSION_FORMAT_BZIP2,
	COMPRESSION_FORMAT_RAR,
	COMPRESSION_FORMAT_TAR,
	COMPRESSION_FORMAT_ISO,
	COMPRESSION_FORMAT_CAB,
	COMPRESSION_FORMAT_LZMA,
	COMPRESSION_FORMAT_LZMA86
};

class SevenZipCallbackHandler;
class UZipFileFunctionInternalCallback;

UCLASS(ClassGroup = ZipUtility, Blueprintable)
class ZIPUTILITY_API UZipFileFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

private:
	static UZipFileFunctionInternalCallback* InternalCallback;

public:
	~UZipFileFunctionLibrary();
	
	/* Unzips file in archive containing Name. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool UnzipFileNamed(const FString& archivePath, const FString& Name, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);
	
	/* Unzips file in archive containing Name at destination path. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool UnzipFileNamedTo(const FString& archivePath, const FString& Name, const FString& destinationPath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);

	/* Unzips file in archive at destination path. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool UnzipFilesTo(const TArray<int32> fileIndices, const FString& archivePath, const FString& destinationPath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);

	/* Unzips specific files in archive at current path. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool UnzipFiles(const TArray<int32> fileIndices, const FString& ArchivePath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);

	/* Unzips archive at current path. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool Unzip(const FString& ArchivePath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);

	/* Unzips archive at destination path. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool UnzipTo(const FString& ArchivePath, const FString& DestinationPath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);

	/* Compresses the file or folder given at path and places the file in the same root folder. Calls ZipUtilityInterface progress events. Not all formats are supported for compression.*/
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool Zip(const FString& FileOrFolderPath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_SEVEN_ZIP);

	/*Queries Archive content list, calls ZipUtilityInterface list events (OnFileFound)*/
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static bool ListFilesInArchive(const FString& ArchivePath, UObject* ZipUtilityInterfaceDelegate, TEnumAsByte<ZipUtilityCompressionFormat> format = COMPRESSION_FORMAT_UNKNOWN);
};

