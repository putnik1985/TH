[Mesh]
 [rectange]
  type = GeneratedMeshGenerator
  xmin = 0.
  xmax = 3.
  ymin = 0.
  ymax = 1.
  nx = 300
  ny = 100
  dim = 2
 []
[]

[Variables]
  [T]
  []
[]

[Kernels]
 [conduction]
  type = HeatConduction 
  variable = T
 []

 [dT_dt]
  type = SpecificHeatConductionTimeDerivative
  specific_heat = 6000.
        density = 3000.
       variable = T
 []
[]

[Materials]
 [thermal]
  type = HeatConductionMaterial
  thermal_conductivity = 12.0
 []
[]

[ICs]
 [constant]
  type = ConstantIC
  variable = T
  value = 320.
 []
[]

[BCs]

  [./bottom] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = bottom # This must match a named boundary in the mesh file
    value = 0.
  [../]

  [./top] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = top # This must match a named boundary in the mesh file
    value = 0.
  [../]

  [./left] # arbitrary user-chosen name
    type = DirichletBC
    variable = T
    boundary = left
    value = 373.15
  [../]

  [./right] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = right
    value = 0.
  [../]
[]

[Executioner]
  type = Transient
  solve_type = 'PJFNK'

  start_time = 0.0
   num_steps = 10
          dt = 0.0001
[]

[Outputs]
  exodus = true
[]
