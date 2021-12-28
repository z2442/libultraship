#include "OTRResourceLoader.h"
#include "OTRMaterialFactory.h"
#include "OTRSceneFactory.h"
#include "OTRCollisionHeaderFactory.h"
#include "OTRDisplayListFactory.h"
#include "OTRPlayerAnimationFactory.h"
#include "OTRSkeletonFactory.h"
#include "OTRSkeletonLimbFactory.h"

namespace OtrLib
{
    OTRResource* OTRResourceLoader::LoadResource(BinaryReader* reader)
    {
        Endianess endianess = (Endianess)reader->ReadByte();
        
        // TODO: Setup the binaryreader to use the resource's endianess
        
        ResourceType resourceType = (ResourceType)reader->ReadUInt32();
        OTRResource* result = nullptr;

        switch (resourceType)
        {
        case ResourceType::OTRMaterial:
            result = OTRMaterialFactory::ReadMaterial(reader);
            break;
        case ResourceType::OTRRoom:
            result = OTRSceneFactory::ReadScene(reader);
            break;
        case ResourceType::OTRCollisionHeader:
            result = OTRCollisionHeaderFactory::ReadCollisionHeader(reader);
            break;
        case ResourceType::OTRDisplayList:
            result = OTRDisplayListFactory::ReadDisplayList(reader);
            break;
        case ResourceType::OTRPlayerAnimation:
            result = OTRPlayerAnimationFactory::ReadPlayerAnimation(reader);
            break;
        case ResourceType::OTRSkeleton:
            result = OTRSkeletonFactory::ReadSkeleton(reader);
            break;
        case ResourceType::OTRSkeletonLimb:
            result = OTRSkeletonLimbFactory::ReadSkeletonLimb(reader);
            break;
        default:
            // RESOURCE TYPE NOT SUPPORTED
            break;
        }

        return result;
    }
}