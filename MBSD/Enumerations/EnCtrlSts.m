classdef  (Enumeration) EnCtrlSts < uint8
	enumeration
		EnCtrlStsIsNormative (0)
		EnCtrlStsIsNoComputedData (2)
		EnCtrlStsIsMplSelrs (3)
		EnCtrlStsIsNeedsCal (7)
		EnCtrlStsIsNotAvl (5)
		EnCtrlStsIsErr (6)
		EnCtrlStsIsDegraded (1)
		EnCtrlStsIsNotCal (4)
	end
	methods (Static = true)
		function retValue = getDefaultValue()
			retValue = EnCtrlSts.EnCtrlStsIsNormative;
		end
		function retValue = getHeaderFile()
			retValue = 'Rte_Type.h';
		end
		function retValue = addClassNameToEnumNames()
			retValue = false;
		end
	end
end
