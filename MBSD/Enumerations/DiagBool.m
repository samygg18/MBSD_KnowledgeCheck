classdef  (Enumeration) DiagBool < uint8
	enumeration
		False (0)
		True (1)
	end
	methods (Static = true)
		function retValue = getDefaultValue()
			retValue = DiagBool.False;
		end
		function retValue = getHeaderFile()
			retValue = 'Rte_Type.h';
		end
		function retValue = addClassNameToEnumNames()
			retValue = false;
		end
	end
end
