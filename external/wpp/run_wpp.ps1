param(
    [parameter(Mandatory=$true)][string]$moduleName,
    [parameter(Mandatory=$true)][string]$wppIni,
    [parameter(Mandatory=$true)][string]$srcDir,
    [parameter(Mandatory=$true)][string]$outDir,
    [switch]$noShrieks)

if (!(Test-Path $outDir))
{
    mkdir $outDir | Out-Null
}

$fileNames = @{}
$srcFiles = Get-ChildItem $srcDir -r -i *.h,*.cpp,*.inl | Where-Object { Select-String -Pattern "#include.*\.tmh" -Path $_ }
foreach ($srcFile in $srcFiles)
{
    if ($srcFile.Extension -eq ".cpp")
    {
        $outFilePath = "$outDir\$($srcFile.BaseName).tmh"
    }
    else
    {
        $outFilePath = "$outDir\$($srcFile.Name).tmh"
    }

    # Because the files go to the same output directory, we can't allow identical names. Track file names as we create
    # them so we can detect duplicates.
    if ($fileNames.ContainsKey($outFilePath))
    {
        throw "Cannot process $outFilePath because an output file with that name already exists."
    }
    $fileNames[$outFilePath] = $true

    $existingOutFile = $null
    if ((Test-Path $outFilePath))
    {
        $existingOutFile = Get-Item $outFilePath
        if ($existingOutFile.LastWriteTimeUtc -gt $srcFile.LastWriteTimeUtc)
        {
            # skip this tmh file since it is newer than the source
            continue;
        }
    }

    $noShrieksStr = ""
    if ($noShrieks)
    {
        $noShrieksStr = "-noshrieks"
    }

    $traceCmd = "$psscriptroot\tracewpp -ext:.h.inl.cpp.H.INL.CPP -preserveext:.h.inl.H.INL $noShrieksStr -defwpp:$wppIni -p:$moduleName $srcFile -cfgdir:$psscriptroot\WppConfig\rev1 -odir:$outDir"
    echo $traceCmd
    Invoke-Expression $traceCmd
    if ($existingOutFile)
    {
        $existingOutFile.LastWriteTime = Get-Date
    }
}
