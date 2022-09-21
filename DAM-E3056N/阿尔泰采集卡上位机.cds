<?xml version="1.0" encoding="UTF-8"?>
<distribution version="20.0.0" name="阿尔泰采集卡上位机" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{293AA6B8-CB3B-4C82-9B3A-82ABA020BC68}">
		<general appName="阿尔泰采集卡上位机" outputLocation="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\cvidistkit.阿尔泰采集卡上位机" relOutputLocation="cvidistkit.阿尔泰采集卡上位机" outputLocationWithVars="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.6">
			<arp company="liudongpeng" companyURL="13289204862@163.com" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="Chinese (Simplified)" showPaths="true" showRuntimeOnly="true" readMe="" license="">
			<dlgstrings welcomeTitle="阿尔泰采集卡上位机" welcomeText=""/></userinterface>
		<dirs appDirID="101">
			<installDir name="阿尔泰采集卡上位机" dirID="100" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="阿尔泰采集卡上位机" dirID="101" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Desktop]" dirID="0" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="C:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAME3000N_64.dll" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="C:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAM-E3056N.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="2" sourcePath="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAM-E3056N.uir" relSourcePath="DAM-E3056N.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<shortcuts>
			<shortcut name="阿尔泰采集卡上位机" targetFileID="1" destDirID="0" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine installToAppDir="false" activeXsup="false" analysis="true" cvirte="true" dotnetsup="true" instrsup="false" lowlevelsup="false" lvrt="false" netvarsup="true" rtutilsup="false">
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
		<baselineProducts/>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="c:\Users\liudongpeng\Desktop\DAM-E3056N\DAM-E3056N\DAM-E3056N.prj" ProjectRelativePath="DAM-E3056N.prj"/></Projects>
		<buildData progressBarRate="34.293330834492579">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.374973250000002</ProductsAdded>
				<DPConfigured>0.590601312499999</DPConfigured>
				<DPMergeModulesAdded>0.877327390624997</DPMergeModulesAdded>
				<DPClosed>1.696557062500002</DPClosed>
				<DistributionsCopied>1.842074000000003</DistributionsCopied>
				<End>2.916018875000004</End></progressTimes></buildData>
	</msi>
</distribution>
