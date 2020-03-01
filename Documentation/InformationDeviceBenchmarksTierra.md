# Information Device Benchmarks (Tierra)

#### Command Use

> sudo lshw -short

#### Output

<pre>

H/W path                 Device      Class       Description
============================================================
                                     system      OEM
/0                                   bus         G31MXP
/0/0                                 memory      128KiB BIOS
/0/4                                 processor   Pentium(R) Dual-Core  CPU      E5700  @ 3.00GHz
/0/4/8                               memory      32KiB L1 cache
/0/4/9                               memory      2MiB L2 cache
/0/2a                                memory      4GiB System Memory
/0/2a/0                              memory      2GiB DIMM Synchronous 5354 MHz (0.2 ns)
/0/2a/1                              memory      2GiB DIMM Synchronous 5354 MHz (0.2 ns)
/0/100                               bridge      82G33/G31/P35/P31 Express DRAM Controller
/0/100/2                             display     82G33/G31 Express Integrated Graphics Controller
/0/100/1b                            multimedia  NM10/ICH7 Family High Definition Audio Controller
/0/100/1c                            bridge      NM10/ICH7 Family PCI Express Port 1
/0/100/1c.1                          bridge      NM10/ICH7 Family PCI Express Port 2
/0/100/1c.1/0            enp2s0      network     RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller
/0/100/1d                            bus         NM10/ICH7 Family USB UHCI Controller #1
/0/100/1d/1              usb2        bus         UHCI Host Controller
/0/100/1d.1                          bus         NM10/ICH7 Family USB UHCI Controller #2
/0/100/1d.1/1            usb3        bus         UHCI Host Controller
/0/100/1d.2                          bus         NM10/ICH7 Family USB UHCI Controller #3
/0/100/1d.2/1            usb4        bus         UHCI Host Controller
/0/100/1d.2/1/2                      input       USB OPTICAL MOUSE
/0/100/1d.3                          bus         NM10/ICH7 Family USB UHCI Controller #4
/0/100/1d.3/1            usb5        bus         UHCI Host Controller
/0/100/1d.3/1/2                      input       2.4G Wireless Device
/0/100/1d.7                          bus         NM10/ICH7 Family USB2 EHCI Controller
/0/100/1d.7/1            usb1        bus         EHCI Host Controller
/0/100/1d.7/1/7          scsi4       storage     Mass Storage Device
/0/100/1d.7/1/7/0.0.0    /dev/sdb    disk        SCSI Disk
/0/100/1d.7/1/7/0.0.1    /dev/sdc    disk        SCSI Disk
/0/100/1d.7/1/7/0.0.2    /dev/sdd    disk        SCSI Disk
/0/100/1d.7/1/7/0.0.3    /dev/sde    disk        MS/MS-Pro
/0/100/1d.7/1/7/0.0.3/0  /dev/sde    disk        
/0/100/1e                            bridge      82801 PCI Bridge
/0/100/1e/2              wlp3s2      network     RTL-8185 IEEE 802.11a/b/g Wireless LAN Controller
/0/100/1f                            bridge      82801GB/GR (ICH7 Family) LPC Interface Bridge
/0/100/1f.1                          storage     82801G (ICH7 Family) IDE Controller
/0/100/1f.2                          storage     NM10/ICH7 Family SATA Controller [IDE mode]
/0/100/1f.3                          bus         NM10/ICH7 Family SMBus Controller
/0/1                     scsi2       storage     
/0/1/0.1.0               /dev/sda    disk        500GB WDC WD5000AAKS-2
/0/1/0.1.0/1             /dev/sda1   volume      465GiB Extended partition
/0/1/0.1.0/1/5           /dev/sda5   volume      93GiB Linux filesystem partition
/0/1/0.1.0/1/6           /dev/sda6   volume      7628MiB Linux swap / Solaris partition
/0/1/0.1.0/1/7           /dev/sda7   volume      7812MiB Linux swap / Solaris partition
/0/1/0.1.0/1/8           /dev/sda8   volume      27GiB Linux filesystem partition
/0/1/0.1.0/1/9           /dev/sda9   volume      94GiB Linux filesystem partition
/0/1/0.1.0/1/a           /dev/sda10  volume      234GiB Linux filesystem partition


</pre>

##### Command Use

> lscpu

##### Output

<pre>

Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                2
On-line CPU(s) list:   0,1
Thread(s) per core:    1
Core(s) per socket:    2
Socket(s):             1
NUMA node(s):          1
Vendor ID:             GenuineIntel
CPU family:            6
Model:                 23
Model name:            Pentium(R) Dual-Core  CPU      E5700  @ 3.00GHz
Stepping:              10
CPU MHz:               1463.475
CPU max MHz:           3000.0000
CPU min MHz:           1200.0000
BogoMIPS:              6025.07
Virtualization:        VT-x
L1d cache:             32K
L1i cache:             32K
L2 cache:              2048K
NUMA node0 CPU(s):     0,1
Flags:                 fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx lm constant_tsc arch_perfmon pebs bts rep_good nopl cpuid aperfmperf pni dtes64 monitor ds_cpl vmx est tm2 ssse3 cx16 xtpr pdcm xsave lahf_lm pti tpr_shadow vnmi flexpriority dtherm

</pre>

##### Command Use

> sudo dmidecode -t processor

##### Output

<pre>

# dmidecode 3.0
Getting SMBIOS data from sysfs.
SMBIOS 2.5 present.

Handle 0x0004, DMI type 4, 40 bytes
Processor Information
	Socket Designation: Socket 775
	Type: Central Processor
	Family: Pentium D
	Manufacturer: Intel
	ID: 7A 06 01 00 FF FB EB BF
	Signature: Type 0, Family 6, Model 23, Stepping 10
	Flags:
		FPU (Floating-point unit on-chip)
		VME (Virtual mode extension)
		DE (Debugging extension)
		PSE (Page size extension)
		TSC (Time stamp counter)
		MSR (Model specific registers)
		PAE (Physical address extension)
		MCE (Machine check exception)
		CX8 (CMPXCHG8 instruction supported)
		APIC (On-chip APIC hardware supported)
		SEP (Fast system call)
		MTRR (Memory type range registers)
		PGE (Page global enable)
		MCA (Machine check architecture)
		CMOV (Conditional move instruction supported)
		PAT (Page attribute table)
		PSE-36 (36-bit page size extension)
		CLFSH (CLFLUSH instruction supported)
		DS (Debug store)
		ACPI (ACPI supported)
		MMX (MMX technology supported)
		FXSR (FXSAVE and FXSTOR instructions supported)
		SSE (Streaming SIMD extensions)
		SSE2 (Streaming SIMD extensions 2)
		SS (Self-snoop)
		HTT (Multi-threading)
		TM (Thermal monitor supported)
		PBE (Pending break enabled)
	Version: Pentium(R) Dual-Core  CPU
	Voltage: 0.0 V
	External Clock: 200 MHz
	Max Speed: 4000 MHz
	Current Speed: 3000 MHz
	Status: Populated, Enabled
	Upgrade: ZIF Socket
	L1 Cache Handle: 0x0008
	L2 Cache Handle: 0x0009
	L3 Cache Handle: Not Provided
	Serial Number:  
	Asset Tag:  
	Part Number:  
	Characteristics: None

</pre>

##### Command Use

> sudo lshw

##### Ouput

<pre>

tierra                    
    description: Desktop Computer
    product: OEM
    vendor: OEM
    version: OEM
    serial: OEM
    width: 64 bits
    capabilities: smbios-2.5 dmi-2.5 vsyscall32
    configuration: boot=normal chassis=desktop uuid=00000000-0000-0000-0807-060504030201
  *-core
       description: Motherboard
       product: G31MXP
       vendor: Foxconn
       physical id: 0
       version: FAB:1.1
     *-firmware
          description: BIOS
          vendor: Phoenix Technologies, LTD
          physical id: 0
          version: 6.00 PG
          date: 05/06/2009
          size: 128KiB
          capacity: 960KiB
          capabilities: isa pci pnp apm upgrade shadowing cdboot bootselect socketedrom edd int13floppy360 int13floppy1200 int13floppy720 int13floppy2880 int5printscreen int9keyboard int14serial int17printer int10video acpi usb ls120boot zipboot biosbootspecification
     *-cpu
          description: CPU
          product: Pentium(R) Dual-Core  CPU      E5700  @ 3.00GHz
          vendor: Intel Corp.
          physical id: 4
          bus info: cpu@0
          version: Pentium(R) Dual-Core  CPU
          slot: Socket 775
          size: 1566MHz
          capacity: 4GHz
          width: 64 bits
          clock: 200MHz
          capabilities: fpu fpu_exception wp vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx x86-64 constant_tsc arch_perfmon pebs bts rep_good nopl cpuid aperfmperf pni dtes64 monitor ds_cpl vmx est tm2 ssse3 cx16 xtpr pdcm xsave lahf_lm pti tpr_shadow vnmi flexpriority dtherm cpufreq
        *-cache:0
             description: L1 cache
             physical id: 8
             slot: Internal Cache
             size: 32KiB
             capacity: 32KiB
             capabilities: synchronous internal write-back
             configuration: level=1
        *-cache:1
             description: L2 cache
             physical id: 9
             slot: External Cache
             size: 2MiB
             capacity: 2MiB
             capabilities: synchronous external write-back
             configuration: level=2
     *-memory
          description: System Memory
          physical id: 2a
          slot: System board or motherboard
          size: 4GiB
        *-bank:0
             description: DIMM Synchronous 5354 MHz (0.2 ns)
             physical id: 0
             slot: A0
             size: 2GiB
             width: 64 bits
             clock: 1059MHz (0.9ns)
        *-bank:1
             description: DIMM Synchronous 5354 MHz (0.2 ns)
             physical id: 1
             slot: A1
             size: 2GiB
             width: 64 bits
             clock: 1059MHz (0.9ns)
     *-pci
          description: Host bridge
          product: 82G33/G31/P35/P31 Express DRAM Controller
          vendor: Intel Corporation
          physical id: 100
          bus info: pci@0000:00:00.0
          version: 10
          width: 32 bits
          clock: 33MHz
        *-display
             description: VGA compatible controller
             product: 82G33/G31 Express Integrated Graphics Controller
             vendor: Intel Corporation
             physical id: 2
             bus info: pci@0000:00:02.0
             version: 10
             width: 32 bits
             clock: 33MHz
             capabilities: msi pm vga_controller bus_master cap_list rom
             configuration: driver=i915 latency=0
             resources: irq:16 memory:fdf00000-fdf7ffff ioport:ff00(size=8) memory:d0000000-dfffffff memory:fda00000-fdafffff memory:c0000-dffff
        *-multimedia
             description: Audio device
             product: NM10/ICH7 Family High Definition Audio Controller
             vendor: Intel Corporation
             physical id: 1b
             bus info: pci@0000:00:1b.0
             version: 01
             width: 64 bits
             clock: 33MHz
             capabilities: pm msi pciexpress bus_master cap_list
             configuration: driver=snd_hda_intel latency=0
             resources: irq:25 memory:fdff8000-fdffbfff
        *-pci:0
             description: PCI bridge
             product: NM10/ICH7 Family PCI Express Port 1
             vendor: Intel Corporation
             physical id: 1c
             bus info: pci@0000:00:1c.0
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: pci pciexpress msi pm normal_decode bus_master cap_list
             configuration: driver=pcieport
             resources: irq:16 ioport:c000(size=4096) memory:fde00000-fdefffff ioport:fdd00000(size=1048576)
        *-pci:1
             description: PCI bridge
             product: NM10/ICH7 Family PCI Express Port 2
             vendor: Intel Corporation
             physical id: 1c.1
             bus info: pci@0000:00:1c.1
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: pci pciexpress msi pm normal_decode bus_master cap_list
             configuration: driver=pcieport
             resources: irq:17 ioport:e000(size=4096) memory:fdc00000-fdcfffff ioport:fdb00000(size=1048576)
           *-network
                description: Ethernet interface
                product: RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller
                vendor: Realtek Semiconductor Co., Ltd.
                physical id: 0
                bus info: pci@0000:02:00.0
                logical name: enp2s0
                version: 03
                serial: 90:fb:a6:93:25:73
                size: 10Mbit/s
                capacity: 1Gbit/s
                width: 64 bits
                clock: 33MHz
                capabilities: pm msi pciexpress msix vpd bus_master cap_list rom ethernet physical tp mii 10bt 10bt-fd 100bt 100bt-fd 1000bt 1000bt-fd autonegotiation
                configuration: autonegotiation=on broadcast=yes driver=r8169 driverversion=2.3LK-NAPI duplex=half firmware=rtl_nic/rtl8168d-2.fw latency=0 link=no multicast=yes port=MII speed=10Mbit/s
                resources: irq:17 ioport:ee00(size=256) memory:fdbff000-fdbfffff memory:fdbf8000-fdbfbfff memory:fdc00000-fdc1ffff
        *-usb:0
             description: USB controller
             product: NM10/ICH7 Family USB UHCI Controller #1
             vendor: Intel Corporation
             physical id: 1d
             bus info: pci@0000:00:1d.0
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: uhci bus_master
             configuration: driver=uhci_hcd latency=0
             resources: irq:23 ioport:fe00(size=32)
           *-usbhost
                product: UHCI Host Controller
                vendor: Linux 4.15.0-46-generic uhci_hcd
                physical id: 1
                bus info: usb@2
                logical name: usb2
                version: 4.15
                capabilities: usb-1.10
                configuration: driver=hub slots=2 speed=12Mbit/s
        *-usb:1
             description: USB controller
             product: NM10/ICH7 Family USB UHCI Controller #2
             vendor: Intel Corporation
             physical id: 1d.1
             bus info: pci@0000:00:1d.1
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: uhci bus_master
             configuration: driver=uhci_hcd latency=0
             resources: irq:19 ioport:fd00(size=32)
           *-usbhost
                product: UHCI Host Controller
                vendor: Linux 4.15.0-46-generic uhci_hcd
                physical id: 1
                bus info: usb@3
                logical name: usb3
                version: 4.15
                capabilities: usb-1.10
                configuration: driver=hub slots=2 speed=12Mbit/s
        *-usb:2
             description: USB controller
             product: NM10/ICH7 Family USB UHCI Controller #3
             vendor: Intel Corporation
             physical id: 1d.2
             bus info: pci@0000:00:1d.2
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: uhci bus_master
             configuration: driver=uhci_hcd latency=0
             resources: irq:18 ioport:fc00(size=32)
           *-usbhost
                product: UHCI Host Controller
                vendor: Linux 4.15.0-46-generic uhci_hcd
                physical id: 1
                bus info: usb@4
                logical name: usb4
                version: 4.15
                capabilities: usb-1.10
                configuration: driver=hub slots=2 speed=12Mbit/s
              *-usb
                   description: Mouse
                   product: USB OPTICAL MOUSE
                   physical id: 2
                   bus info: usb@4:2
                   version: 1.00
                   capabilities: usb-1.10
                   configuration: driver=usbhid maxpower=100mA speed=2Mbit/s
        *-usb:3
             description: USB controller
             product: NM10/ICH7 Family USB UHCI Controller #4
             vendor: Intel Corporation
             physical id: 1d.3
             bus info: pci@0000:00:1d.3
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: uhci bus_master
             configuration: driver=uhci_hcd latency=0
             resources: irq:16 ioport:fb00(size=32)
           *-usbhost
                product: UHCI Host Controller
                vendor: Linux 4.15.0-46-generic uhci_hcd
                physical id: 1
                bus info: usb@5
                logical name: usb5
                version: 4.15
                capabilities: usb-1.10
                configuration: driver=hub slots=2 speed=12Mbit/s
              *-usb
                   description: Mouse
                   product: 2.4G Wireless Device
                   vendor: YK
                   physical id: 2
                   bus info: usb@5:2
                   version: 3.11
                   capabilities: usb-1.10
                   configuration: driver=usbhid maxpower=100mA speed=2Mbit/s
        *-usb:4
             description: USB controller
             product: NM10/ICH7 Family USB2 EHCI Controller
             vendor: Intel Corporation
             physical id: 1d.7
             bus info: pci@0000:00:1d.7
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: pm debug ehci bus_master cap_list
             configuration: driver=ehci-pci latency=0
             resources: irq:23 memory:fdfff000-fdfff3ff
           *-usbhost
                product: EHCI Host Controller
                vendor: Linux 4.15.0-46-generic ehci_hcd
                physical id: 1
                bus info: usb@1
                logical name: usb1
                version: 4.15
                capabilities: usb-2.00
                configuration: driver=hub slots=8 speed=480Mbit/s
              *-usb
                   description: Mass storage device
                   product: Mass Storage Device
                   vendor: Generic
                   physical id: 7
                   bus info: usb@1:7
                   logical name: scsi4
                   version: 1.00
                   serial: 058F63646476
                   capabilities: usb-2.00 scsi emulated scsi-host
                   configuration: driver=usb-storage maxpower=250mA speed=480Mbit/s
                 *-disk:0
                      description: SCSI Disk
                      physical id: 0.0.0
                      bus info: scsi@4:0.0.0
                      logical name: /dev/sdb
                      configuration: logicalsectorsize=512 sectorsize=512
                 *-disk:1
                      description: SCSI Disk
                      physical id: 0.0.1
                      bus info: scsi@4:0.0.1
                      logical name: /dev/sdc
                      configuration: logicalsectorsize=512 sectorsize=512
                 *-disk:2
                      description: SCSI Disk
                      physical id: 0.0.2
                      bus info: scsi@4:0.0.2
                      logical name: /dev/sdd
                      configuration: logicalsectorsize=512 sectorsize=512
                 *-disk:3
                      description: SCSI Disk
                      product: MS/MS-Pro
                      vendor: Generic-
                      physical id: 0.0.3
                      bus info: scsi@4:0.0.3
                      logical name: /dev/sde
                      version: 1.03
                      serial: 3
                      capabilities: removable
                      configuration: logicalsectorsize=512 sectorsize=512
                    *-medium
                         physical id: 0
                         logical name: /dev/sde
        *-pci:2
             description: PCI bridge
             product: 82801 PCI Bridge
             vendor: Intel Corporation
             physical id: 1e
             bus info: pci@0000:00:1e.0
             version: e1
             width: 32 bits
             clock: 33MHz
             capabilities: pci subtractive_decode bus_master cap_list
             resources: ioport:d000(size=4096) memory:fd900000-fd9fffff ioport:fd800000(size=1048576)
           *-network DISABLED
                description: Wireless interface
                product: RTL-8185 IEEE 802.11a/b/g Wireless LAN Controller
                vendor: Realtek Semiconductor Co., Ltd.
                physical id: 2
                bus info: pci@0000:03:02.0
                logical name: wlp3s2
                version: 20
                serial: 00:18:e7:76:e9:bf
                width: 32 bits
                clock: 33MHz
                capabilities: pm bus_master cap_list ethernet physical wireless
                configuration: broadcast=yes driver=rtl818x_pci driverversion=4.15.0-46-generic firmware=N/A latency=32 link=no maxlatency=64 mingnt=32 multicast=yes wireless=IEEE 802.11
                resources: irq:17 ioport:de00(size=256) memory:fd9ff000-fd9ff3ff
        *-isa
             description: ISA bridge
             product: 82801GB/GR (ICH7 Family) LPC Interface Bridge
             vendor: Intel Corporation
             physical id: 1f
             bus info: pci@0000:00:1f.0
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: isa bus_master cap_list
             configuration: driver=lpc_ich latency=0
             resources: irq:0
        *-ide:0
             description: IDE interface
             product: 82801G (ICH7 Family) IDE Controller
             vendor: Intel Corporation
             physical id: 1f.1
             bus info: pci@0000:00:1f.1
             version: 01
             width: 32 bits
             clock: 33MHz
             capabilities: ide isa_compatibility_mode_controller__supports_both_channels_switched_to_pci_native_mode__supports_bus_mastering bus_master
             configuration: driver=ata_piix latency=0
             resources: irq:18 ioport:1f0(size=8) ioport:3f6 ioport:170(size=8) ioport:376 ioport:fa00(size=16)
        *-ide:1
             description: IDE interface
             product: NM10/ICH7 Family SATA Controller [IDE mode]
             vendor: Intel Corporation
             physical id: 1f.2
             bus info: pci@0000:00:1f.2
             version: 01
             width: 32 bits
             clock: 66MHz
             capabilities: ide pm pci_native_mode_controller__supports_both_channels_switched_to_isa_compatibility_mode__supports_bus_mastering bus_master cap_list
             configuration: driver=ata_piix latency=0
             resources: irq:19 ioport:f900(size=8) ioport:f800(size=4) ioport:f700(size=8) ioport:f600(size=4) ioport:f500(size=16)
        *-serial UNCLAIMED
             description: SMBus
             product: NM10/ICH7 Family SMBus Controller
             vendor: Intel Corporation
             physical id: 1f.3
             bus info: pci@0000:00:1f.3
             version: 01
             width: 32 bits
             clock: 33MHz
             configuration: latency=0
             resources: ioport:500(size=32)
     *-scsi
          physical id: 1
          logical name: scsi2
          capabilities: emulated
        *-disk
             description: ATA Disk
             product: WDC WD5000AAKS-2
             vendor: Western Digital
             physical id: 0.1.0
             bus info: scsi@2:0.1.0
             logical name: /dev/sda
             version: 1D05
             serial: WD-WCAWF6533428
             size: 465GiB (500GB)
             capabilities: partitioned partitioned:dos
             configuration: ansiversion=5 logicalsectorsize=512 sectorsize=512 signature=0008250a
           *-volume
                description: Extended partition
                physical id: 1
                bus info: scsi@2:0.1.0,1
                logical name: /dev/sda1
                size: 465GiB
                capacity: 465GiB
                capabilities: primary extended partitioned partitioned:extended
              *-logicalvolume:0
                   description: Linux filesystem partition
                   physical id: 5
                   logical name: /dev/sda5
                   capacity: 93GiB
              *-logicalvolume:1
                   description: Linux swap / Solaris partition
                   physical id: 6
                   logical name: /dev/sda6
                   capacity: 7628MiB
                   capabilities: nofs
              *-logicalvolume:2
                   description: Linux swap / Solaris partition
                   physical id: 7
                   logical name: /dev/sda7
                   capacity: 7812MiB
                   capabilities: nofs
              *-logicalvolume:3
                   description: Linux filesystem partition
                   physical id: 8
                   logical name: /dev/sda8
                   logical name: /
                   capacity: 27GiB
                   configuration: mount.fstype=ext4 mount.options=rw,relatime,errors=remount-ro,data=ordered state=mounted
              *-logicalvolume:4
                   description: Linux filesystem partition
                   physical id: 9
                   logical name: /dev/sda9
                   logical name: /home
                   capacity: 94GiB
                   configuration: mount.fstype=ext4 mount.options=rw,relatime,data=ordered state=mounted
              *-logicalvolume:5
                   description: Linux filesystem partition
                   physical id: a
                   logical name: /dev/sda10
                   capacity: 234GiB

</pre>
