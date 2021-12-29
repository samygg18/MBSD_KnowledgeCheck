classdef  (Enumeration) EnCtrlDisSt < uint8
	enumeration
		EnCtrlDisStIsOff (0)
		EnCtrlDisStIsOn (1)
		EnCtrlDisStIsHoldSho (2)
		EnCtrlDisStIsHoldLong (3)
	end
	methods (Static = true)
		function retValue = getDefaultValue()
			retValue = EnCtrlDisSt.EnCtrlDisStIsOff;
		end
		function retValue = getHeaderFile()
			retValue = 'Rte_Type.h';
		end
		function retValue = addClassNameToEnumNames()
			retValue = false;
		end
	end
end
