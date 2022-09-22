<?xml version="1.0" encoding="UTF-8"?>
<distribution version="20.0.0" name="阿尔泰采集卡上位机" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{293AA6B8-CB3B-4C82-9B3A-82ABA020BC68}">
		<general appName="阿尔泰采集卡上位机" outputLocation="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\cvidistkit.阿尔泰采集卡上位机" relOutputLocation="cvidistkit.阿尔泰采集卡上位机" outputLocationWithVars="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.8">
			<arp company="liudongpeng" companyURL="13289204862@163.com" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="Chinese (Simplified)" showPaths="true" showRuntimeOnly="true" readMe="" license="">
			<dlgstrings welcomeTitle="阿尔泰采集卡上位机" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Desktop]" dirID="0" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="阿尔泰采集卡上位机" dirID="100" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="阿尔泰采集卡上位机" dirID="101" parentID="7" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="C:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAME3000N_64.dll" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="C:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAM-E3056N.exe" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="2" sourcePath="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAM-E3056N.uir" relSourcePath="DAM-E3056N.uir" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<shortcuts>
			<shortcut name="阿尔泰采集卡上位机" targetFileID="1" destDirID="0" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products>
			<product name="NI LabWindows/CVI Shared Runtime 2020 f2" UC="{80D3D303-75B9-4607-9312-E5FC68E5BFD2}" productID="{DE72BF5F-7980-4210-BE46-772981ED334C}" path="C:\ProgramData\National Instruments\MDF\ProductCache\" flavorID="_full_" flavorName="Full" verRestr="false" coreVer="20.2.49152">
				<cutSoftDeps/></product></products>
		<runtimeEngine installToAppDir="false" activeXsup="false" analysis="true" cvirte="true" dotnetsup="true" instrsup="true" lowlevelsup="true" lvrt="true" netvarsup="true" rtutilsup="true">
			<hasSoftDeps/>
			<doNotAutoSelect>
			<component>activeXsup</component>
			</doNotAutoSelect></runtimeEngine><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<exeName>install.exe</exeName>
			<launchConditions>
				<condition>MINOS_WIN7_SP1</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<baselineProducts>
			<product name="NI LabWindows/CVI Shared Runtime 2020 f2" UC="{80D3D303-75B9-4607-9312-E5FC68E5BFD2}" productID="{DE72BF5F-7980-4210-BE46-772981ED334C}" path="(None)" flavorID="_full_" flavorName="Full" verRestr="false" coreVer="20.2.49152">
				<dependencies>
					<productID>{054A4C14-7D56-4383-949B-F9B91E094F4B}</productID>
					<productID>{0B476064-821E-4BA8-A0A8-489ECDDAAD55}</productID>
					<productID>{1268324B-6C67-48D3-B58A-845E81AE6AFE}</productID>
					<productID>{195D8F29-2704-44BD-A978-57A0382327E5}</productID>
					<productID>{28B285EA-90C8-4C3A-94C0-B0196A3FEF07}</productID>
					<productID>{3F36AC37-CC28-4780-AF19-D80ACEDE0323}</productID>
					<productID>{41BDEA25-514E-4BDA-AC47-186E97C9D3F7}</productID>
					<productID>{43C6873A-8548-4944-AF22-8B1C3312A070}</productID>
					<productID>{539F08CF-F2FD-482C-A5ED-65FD2620789D}</productID>
					<productID>{56F2F3B5-8222-44E6-AE2F-B3C0B6041105}</productID>
					<productID>{64ECB814-3A6A-4E48-9D2F-D6C2EDD725B7}</productID>
					<productID>{67CFC7DD-BF77-4D45-9AE9-742AA8658AE7}</productID>
					<productID>{70D25297-8E78-49EF-B639-FA51D33A4CE1}</productID>
					<productID>{71A3C9EA-E231-454D-9F2E-607B6018D9C6}</productID>
					<productID>{74E23E08-6C6D-4F8F-A62A-020FA19F7FCB}</productID>
					<productID>{87749B2B-2175-4F7E-BE4C-FB13D0CCB0EF}</productID>
					<productID>{9905478F-5785-468A-A35A-D84325D61EB8}</productID>
					<productID>{A12FB799-41BF-4A9A-98F2-2FE4F333B718}</productID>
					<productID>{A5250560-F2D6-4275-9BCB-04FA5D3C3005}</productID>
					<productID>{A7BC6F18-28B4-4D26-9C6C-802B3A8DA0F8}</productID>
					<productID>{B524884D-C3AC-417A-939E-34A16118A14C}</productID>
					<productID>{BC9B5AF5-B10A-447C-8872-634518DC70B6}</productID>
					<productID>{C03716B7-FB4A-4479-A370-12D79AC30EAA}</productID>
					<productID>{C18DA001-CF46-48A5-8DDB-322EA6DBFB4F}</productID>
					<productID>{D8F71C3E-C0AE-4D69-920E-7D927C950A1A}</productID>
					<productID>{DCCB918E-584B-4FAF-BDA4-EF5A7B90C4C1}</productID>
					<productID>{DEDA7399-29FE-40A5-8B64-F630D40EF8C0}</productID>
					<productID>{E0DAF96D-BF67-46CD-87A7-45E7E12A8074}</productID>
					<productID>{EB6C9E35-CBA2-4C2B-8958-55EA6F0EA707}</productID>
					<productID>{EDEDDCAE-21E6-4A82-9B58-8E6337386685}</productID>
					<productID>{F13AF45F-DDCC-45C0-AE87-436378E43F68}</productID>
					<productID>{F2EEE63A-0DCA-41BF-A243-4E4C0DFA38A4}</productID>
					<productID>{FD58B244-C5D6-4842-8940-6F315FCF717F}</productID></dependencies></product></baselineProducts>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAM-E3056N.prj" ProjectRelativePath="DAM-E3056N.prj"/></Projects>
		<buildData progressBarRate="15.052791149922514">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.341442812499923</ProductsAdded>
				<DPConfigured>0.507849578124803</DPConfigured>
				<DPMergeModulesAdded>0.704551597656106</DPMergeModulesAdded>
				<DPClosed>1.209338265625026</DPClosed>
				<DistributionsCopied>1.321100500000095</DistributionsCopied>
				<End>6.643286218749854</End></progressTimes></buildData>
	</msi>
</distribution>
