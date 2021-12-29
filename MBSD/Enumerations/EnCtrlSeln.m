classdef  (Enumeration) EnCtrlSeln < uint8
	enumeration
		EnCtrlSelnIsNone (0)
		EnCtrlSelnIsLock (1)
		EnCtrlSelnIsFwdUpRiInnrDetent (2)
		EnCtrlSelnIsBackwDwnLeInnrDetent (3)
		EnCtrlSelnIsFwdUpRiOutrDetent (4)
		EnCtrlSelnIsBackwDwnLeOutrDetent (5)
		EnCtrlSelnIsAltv1 (6)
		EnCtrlSelnIsAltv2 (7)
		EnCtrlSelnIsAltv3 (8)
		EnCtrlSelnIsAltv4 (9)
		EnCtrlSelnIsPark (10)
		EnCtrlSelnIsNeut (11)
		EnCtrlSelnIsLeInnrCentrDetent (12)
		EnCtrlSelnIsLeOutrCentrDetent (13)
		EnCtrlSelnIsRiInnrCentrDetent (14)
		EnCtrlSelnIsRiOutrCentrDetent (15)
		EnCtrlSelnIsLeInnrFwdInnrDetent (16)
		EnCtrlSelnIsLeOutrFwdInnrDetent (17)
		EnCtrlSelnIsRiInnrFwdInnrDetent (18)
		EnCtrlSelnIsRiOutrFwdInnrDetent (19)
		EnCtrlSelnIsLeInnrFwdOutrDetent (20)
		EnCtrlSelnIsLeOutrFwdOutrDetent (21)
		EnCtrlSelnIsRiInnrFwdOutrDetent (22)
		EnCtrlSelnIsRiOutrFwdOutrDetent (23)
		EnCtrlSelnIsLeInnrRearwardInnrDetent (24)
		EnCtrlSelnIsLeOutrRearwardInnrDetent (25)
		EnCtrlSelnIsRiInnrRearwardInnrDetent (26)
		EnCtrlSelnIsRiOutrRearwardInnrDetent (27)
		EnCtrlSelnIsLeInnrRearwardOutrDetent (28)
		EnCtrlSelnIsLeOutrRearwardOutrDetent (29)
		EnCtrlSelnIsRiInnrRearwardOutrDetent (30)
		EnCtrlSelnIsRiOutrRearwardOutrDetent (31)
		EnCtrlSelnIsCentrFwdInnrDetent (32)
		EnCtrlSelnIsCentrFwdOutrDetent (33)
		EnCtrlSelnIsCentrRearwardInnrDetent (34)
		EnCtrlSelnIsCentrRearwardOutrDetent (35)
	end
	methods (Static = true)
		function retValue = getDefaultValue()
			retValue = EnCtrlSeln.EnCtrlSelnIsNone;
		end
		function retValue = getHeaderFile()
			retValue = 'Rte_Type.h';
		end
		function retValue = addClassNameToEnumNames()
			retValue = false;
		end
	end
end
