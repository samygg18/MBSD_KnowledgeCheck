classdef  (Enumeration) Dem_EventStatusType < uint8
	enumeration
		DEM_EVENT_STATUS_PASSED (0)
		DEM_EVENT_STATUS_FAILED (1)
		DEM_EVENT_STATUS_PREPASSED (2)
		DEM_EVENT_STATUS_PREFAILED (3)
	end
	methods (Static = true)
		function retValue = getDefaultValue()
			retValue = Dem_EventStatusType.DEM_EVENT_STATUS_PASSED;
		end
		function retValue = getHeaderFile()
			retValue = 'Rte_Type.h';
		end
		function retValue = addClassNameToEnumNames()
			retValue = false;
		end
	end
end
